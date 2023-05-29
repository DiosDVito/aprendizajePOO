#ifndef CUADRADO_H
#define CUADRADO_H
#include "Rectangulo.h"

class Cuadrado:public Rectangulo{
    public:
        Cuadrado(double lado);
        Cuadrado();
        void imprimir();
};



#endif