#ifndef FIGURA_h
#define FIGURA_h
#include <iostream>
using namespace std;

class Figura{
    public:
        virtual double perimetro()=0;
        virtual double area()=0;
        virtual double volumen()=0;
        virtual void imprimir()=0;
        
};
#endif