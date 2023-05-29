#include "Cuadrado.h"

Cuadrado::Cuadrado(double lado):Rectangulo(lado,lado){
}

Cuadrado::Cuadrado():Cuadrado(3.0){
}

void Cuadrado::imprimir(){
    std::cout<<"Soy un cuadrado de largo: "<< this->largo << " y de ancho: " << this->ancho << std::endl;
}