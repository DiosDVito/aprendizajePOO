#ifndef CUADRADO_h
#define CUADRADO_h
#include "Rectangulo.h"

class Cuadrado:public Rectangulo{
    private:
        double lado;
    public:
        Cuadrado();
        Cuadrado(double);
        void imprimir();
};


#endif
