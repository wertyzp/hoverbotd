/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: werty
 *
 * Created on October 11, 2019, 10:13 PM
 */

#include <cstdlib>

using namespace std;

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <exception>
#include <cstdlib>
#include <signal.h>
#include <sys/stat.h>
#include "bipropellant-hoverboard-api/src/HoverboardAPI.h"
#include "Server.h"


const unsigned int bufferSize = 1024;

control lastctrl;

class TTY {
private:
    struct termios tio;
    int tty_fd;
    
public:
    TTY(const char * path) {
        tty_fd=open(path, O_RDWR | O_NONBLOCK);
        if (tty_fd == -1) {
            throw new TextException("Failed to open dev");
        }
        cfsetospeed(&tio,B115200);            // 115200 baud
        cfsetispeed(&tio,B115200);            // 115200 baud
        cfmakeraw(&tio);
        tio.c_cflag |= (CLOCAL | CREAD);
        tcsetattr(tty_fd,TCSAFLUSH,&tio);
    }
    
    void readTo(unsigned char *buf, int *len) {
        unsigned char c;
        int total = 0;
        for (int i = 0; i < bufferSize; i++) {
            if (read(tty_fd,&c,1)>0) {
                buf[i] = c;
                total++;
            } else {
                break;
            }
        }
        printf("Read %d bytes\n", total);
        *len = total;
    }
    
    int writeFrom(unsigned char *str, int len) {
        int total = 0;
        for (int i =0; i < len; i++) {
            write(tty_fd,&str[i],1);
            total++;
        }
        printf("Wrote %d bytes\n", total);
        return total;
    }
    
    virtual ~TTY() {
        close(tty_fd);
    }

};

int pwm=0;
int steer=0;

void sigint_handler(int sig)
{
    interrupted = 1;
}

TTY *tty;
TTY *tty2;
HoverboardAPI* ha;
HoverboardAPI* ha2;
Server *server;
int writeTTY(unsigned char *str, int len) {
    return tty->writeFrom(str, len);
}

int writeTTY2(unsigned char *str, int len) {
    return tty2->writeFrom(str, len);
}

int main(int argc, const char** argv)
{
    if (false) {
        /* Our process ID and Session ID */
        pid_t pid, sid;

        /* Fork off the parent process */
        pid = fork();
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
        /* If we got a good PID, then
           we can exit the parent process. */
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }

        /* Change the file mode mask */
        umask(0);

        /* Open any logs here */        

        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }

        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
    }
    /* Daemon-specific initialization goes here */
    unsigned char buf[bufferSize];
    int len;
    signal(SIGINT, sigint_handler);
    
    if (argc < 3) {
        fprintf(stderr, "Please specify devs");
        return EXIT_FAILURE;       
    }
    
    try {
        tty = new TTY(argv[1]);
        tty2 = new TTY(argv[2]);
        ha = new HoverboardAPI(writeTTY);
        ha2 = new HoverboardAPI(writeTTY2);
        server = new Server(argc, argv);
    /* The Big Loop */
        while (1) {
            /* Do some task here ... */
            len = 0;
            tty->readTo(buf, &len);
            for (int i =0; i < len; i++) {
                 ha->protocolPush(buf[i]);
            }
            
            len = 0;
            tty2->readTo(buf, &len);
            for (int i =0; i < len; i++) {
                 ha2->protocolPush(buf[i]);
            }
            
            server->service();
            if (lastctrl.forward) {
                pwm += 5;
            }
            if (lastctrl.backward) {
                pwm -= 5;
            }
            if (lastctrl.left) {
                steer -= 5;
            }
            if (lastctrl.right) {
                steer += 5;
            }
            
            if (!lastctrl.forward && !lastctrl.backward && !lastctrl.left && !lastctrl.right) {
                pwm = pwm * 0.95;
                if (abs(pwm) < 10) {
                    pwm = 0;
                }
                steer = steer * 0.95;
                if (abs(steer) < 10) {
                    steer = 0;
                }
            }
            usleep(50*1000);
            printf("forward: %d, backward: %d, left: %d, right:%d\n", lastctrl.forward, lastctrl.backward, lastctrl.left, lastctrl.right);
            printf("pwm: %d, steer: %d\n", pwm, steer);
            ha->sendPWM(pwm, steer, PROTOCOL_SOM_NOACK);
            ha2->sendPWM(-pwm, steer, PROTOCOL_SOM_NOACK);
            /*
            ha->requestRead(HoverboardAPI::Codes::sensElectrical);
            float voltage = ha->getBatteryVoltage();
            printf("Voltage=%f\n", voltage);
            */
            if (interrupted) {
                break;
            }
        }
    } catch (exception &e) {
        fprintf(stderr, "Exception occured: %s", e.what());
        return EXIT_FAILURE;
    }
    exit(EXIT_SUCCESS);
}
