#ifndef RECTANGULO_h
#define RECTANGULO_h
#include "Figura.h"

class Rectangulo:public Figura{
    protected:
        double largo, ancho;
    public:
        Rectangulo();
        Rectangulo(double, double);
        double perimetro();
        double area();
        void imprimir();
};

#endif