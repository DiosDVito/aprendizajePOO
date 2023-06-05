#include "polar.h"

Polar::Polar(){
    this -> r = this -> a = 0.0;
}

Polar::Polar(double r, double a){
    this -> r = r;
    this -> a = a;
}

double Polar::getR(){
    return this -> r;
}

double Polar::getA(){
    return this -> a;
}