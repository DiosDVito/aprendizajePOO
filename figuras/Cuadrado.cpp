#include "Cuadrado.h"
#include <iostream>
using namespace std;

Cuadrado::Cuadrado():Cuadrado(3.0){}

Cuadrado::Cuadrado(double lado):Rectangulo(lado,lado){}

void Cuadrado:: imprimir(){
    cout<<"Soy un cuadrado de lado: "<<this->largo<<endl;
}

void Cuadrado:: saludar(){
    cout<<"Hola, un saludo a la grasa :v"<<endl;
}
