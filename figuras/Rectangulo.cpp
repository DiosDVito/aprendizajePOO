#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo():Rectangulo(4.0,2.0){ //Reutilizacion de codigo
    //this->largo=4.5;
    //this->ancho=2.3;
}
Rectangulo::Rectangulo(double largo, double ancho){
    this->largo = largo;
    this->ancho = ancho;
}

double Rectangulo::perimetro(){
    return 2.0*(largo+ancho);
   
}

double Rectangulo::area(){
    return this->largo*this->ancho;
   
}

double Rectangulo::volumen(){
    return 0.0;
}

void Rectangulo::imprimir(){
    cout<<"Soy un rectangulo de largo: "<<this->largo<<" y ancho: "<<this->ancho<<endl;
}
