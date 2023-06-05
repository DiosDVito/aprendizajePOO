#ifndef RECTANGULAR.H
#define RECTANGULAR.H
#include "polar.h"
#include <string>
#include <iostream>

class Rectangular{
    private:
        double x;
        double y;

    public:
        Rectangular();
        Rectangular(double x, double y);
        double getX();
        double getY();
        Rectangular suma(Rectangular a);
        Rectangular operator+(Rectangular a);
        Rectangular resta(Rectangular a);
        Rectangular multiplicacion(Rectangular a);
        Rectangular division(Rectangular a);
        Polar cambioPolar();
        std::string toString();

        friend std::ostream& operator<<(std::ostream& os, Rectangular& rec){
            os<<"("<<rec.x<<","<<rec.y<<")";
            return os;
        }
};


#endif