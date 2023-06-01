#include "Caja.h"

Caja::Caja(double largo, double ancho, double alto): Rectangulo(largo, ancho){
    this->alto = alto;
}

Caja::Caja():Caja(4.0, 6.0,8.0){}

double Caja::perimetro(){
    return 4.0*largo+ 2.0*ancho + 8.0*alto;
}

double Caja::area(){
    return 2.0*((Rectangulo::area())+(largo*alto)+(ancho*alto));
}

double Caja::volumen(){
    return alto*Rectangulo::area();
    
}

void Caja::imprimir(){
    cout<<"Soy una caja de largo: "<<this->largo<<" ancho: "<<this->ancho<<" alto: "<<this->alto<<endl;
}