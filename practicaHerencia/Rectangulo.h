#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <iostream>

class Rectangulo:public Figura{
    protected:
        double largo;
        double ancho;
    public:
        Rectangulo();
        Rectangulo(double,double);
        double perimetro();
        double area();
        void imprimir();
};

#endif