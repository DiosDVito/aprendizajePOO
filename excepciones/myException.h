#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class MyException:public exception{
    private:
        string mensaje;
    public:
        MyException(string mensaje);
        string what();

};

#endif