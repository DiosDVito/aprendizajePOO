#ifndef CAJA_h
#define CAJA_h
#include "Rectangulo.h"

class Caja:public Rectangulo{
    private:
        double alto;
    public:
        Caja();
        Caja(double, double, double);
        double perimetro();
        double area();
        double volumen();
        void imprimir();

};


#endif