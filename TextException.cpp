#include "TextException.h"
#include <cstring>
TextException::TextException(const char * text) {
    _text = new char[strlen(text) + 1];
    strcpy(_text, text);
}

const char* TextException::what() const throw () {
    return _text;
}

TextException::~TextException() {
    if (_text != NULL) {
        delete _text;
    }
}

