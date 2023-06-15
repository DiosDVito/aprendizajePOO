//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#ifndef PRODUCTOIVA_H
#define PRODUCTOIVA_H

#include "producto.h"

class ProductoIVA : public Producto {
    public:
        ProductoIVA(); //constructor por defecto
        ProductoIVA(int, std::string, double); //constructor con parámetros sin cantidad
        ProductoIVA(int, std::string, double, int); //constructor con parámetros con cantidad
        double getImpuestos() override; // Sobre escribe los impuestos
};

#endif 
