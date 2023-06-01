#include "Figura.h"
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Caja.h"
#include <iostream>
using namespace std;

int main(){
    Figura fig1;
    fig1.imprimir();
    cout<<"Perimetro: "<<fig1.perimetro()<<endl;
    cout<<"Area: "<<fig1.area()<<endl;
    cout<<"Volumen: "<<fig1.volumen()<<endl;
    cout<<endl;

    Rectangulo rec1;
    rec1.imprimir();
    cout<<"Perimetro: "<<rec1.perimetro()<<endl;
    cout<<"Area: "<<rec1.area()<<endl;
    cout<<"Volumen: "<<rec1.volumen()<<endl;
    cout<<endl;

    Rectangulo rec2(7.0, 4.0);
    rec2.imprimir();
    cout<<"Perimetro: "<<rec2.perimetro()<<endl;
    cout<<"Area: "<<rec2.area()<<endl;
    cout<<"Volumen: "<<rec2.volumen()<<endl;
    cout<<endl;

    Cuadrado cua1(7.0);
    cua1.imprimir();
    cout<<"Perimetro: "<<cua1.perimetro()<<endl;
    cout<<"Area: "<<cua1.area()<<endl;
    cout<<"Volumen: "<<cua1.volumen()<<endl;
    cout<<endl;

    Cuadrado cua2;
    cua2.imprimir();
    cout<<"Perimetro: "<<cua2.perimetro()<<endl;
    cout<<"Area: "<<cua2.area()<<endl;
    cout<<"Volumen: "<<cua2.volumen()<<endl;
    cout<<endl;

    Caja caja1;
    caja1.imprimir();
    cout<<"Perimetro: "<<caja1.perimetro()<<endl;
    cout<<"Area: "<<caja1.area()<<endl;
    cout<<"Volumen: "<<caja1.volumen()<<endl;
    cout<<endl;

    Caja caja2(5.0, 7.0, 2.0);
    caja1.imprimir();
    cout<<"Perimetro: "<<caja2.perimetro()<<endl;
    cout<<"Area: "<<caja2.area()<<endl;
    cout<<"Volumen: "<<caja2.volumen()<<endl;
    cout<<endl;
}