//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>

class Producto {
    protected:
        int codigo; //Representa el ID del producto
        std::string descripcion; //Es la descripcion del producto
        double precio; //Es el precio unitario sin impuestos
        int cantidad; //Es la cantidad de articulos que se estan comprando
    public:
        Producto(int,std::string,double,int); //Constructor con parametros
        Producto(int,std::string,double); //Constructor con parametros sin cantidad
        double getSubTotal(); //Total a pagar sin considerar impuestos
        virtual double getImpuestos(); //Total de impuestos
        virtual double getTotal(); //Total a pagar con impuestos
};

#endif