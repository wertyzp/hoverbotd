/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Server.h
 * Author: werty
 *
 * Created on October 13, 2019, 12:21 AM
 */

#ifndef SERVER_H
#define SERVER_H

extern "C" {
    #include <libwebsockets.h>
}
#include "TextException.h"
static int interrupted = 0;

class Server {
public:
    Server(int argc, const char **argv);
    void service();
    virtual ~Server();
private:
    struct lws_context_creation_info info;
    struct lws_context *context;
};

#endif /* SERVER_H */

