//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#include "ProductoIVA.h"

//Constructor con parámetros sin cantidad
ProductoIVA::ProductoIVA(int _codigo, std::string _descripcion, double _precio) : Producto(_codigo, _descripcion, _precio) {}

//Constructor con parámetros con cantidad
ProductoIVA::ProductoIVA(int _codigo, std::string _descripcion, double _precio, int _cantidad) : Producto(_codigo, _descripcion, _precio, _cantidad) {}


double ProductoIVA::getImpuestos() {
    //IVA del 16%
    return getSubTotal() * 0.16;
}
