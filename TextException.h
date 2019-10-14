/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextException.h
 * Author: werty
 *
 * Created on October 13, 2019, 12:38 AM
 */

#ifndef TEXTEXCEPTION_H
#define TEXTEXCEPTION_H

#include <exception>
#include <cstdlib>

class TextException : public std::exception {
public:
    TextException(const char * text);
    virtual ~TextException();
    virtual const char * what() const throw();
private:
    char * _text = NULL;
};



#endif /* TEXTEXCEPTION_H */

