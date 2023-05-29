#include "Rectangulo.h"

Rectangulo::Rectangulo():Rectangulo(4.5,2.3){}

Rectangulo::Rectangulo(double largo, double ancho){
    this -> largo = largo;
    this -> ancho = ancho;
}

double Rectangulo::perimetro(){
    return 2.0*(largo+ancho);
}

double Rectangulo::area(){
    return this->largo * this->ancho;
}

void Rectangulo::imprimir(){
    std::cout<<"Soy un rectangulo de largo: "<< largo << " y de ancho: " << ancho << std::endl;
}