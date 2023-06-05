#include "rectangular.h"
#include <math.h>

Rectangular::Rectangular(){
    this -> x = this -> y =0.0;
}

Rectangular::Rectangular(double x, double y){
    this -> x = x;
    this -> y = y;
}

double Rectangular::getX(){
    return this -> x;
}

double Rectangular::getY(){
    return this -> y;
}

Polar Rectangular::cambioPolar(){
    double r= sqrt(this -> x*this -> x+this -> y*this -> y);
    double a= atan2(this -> y, this -> x);
    return Polar(r,a);
}

Rectangular Rectangular::suma(Rectangular a){
    return Rectangular(this -> x + a.x,this -> y + a.y);
}

Rectangular Rectangular::resta(Rectangular a){
    return Rectangular(this -> x - a.x,this -> y - a.y);
}

Rectangular Rectangular::multiplicacion(Rectangular a){
    return Rectangular(this -> x * a.x,this -> y * a.y);
}

Rectangular Rectangular::division(Rectangular a){
    return Rectangular(this -> x / a.x,this -> y / a.y);
}

std::string Rectangular::toString(){
    return "("+std::to_string(this->x)+","+std::to_string(this->y)+")";
}

Rectangular Rectangular::operator+(Rectangular a){
    return Rectangular(this -> x + a.x,this -> y + a.y);
}