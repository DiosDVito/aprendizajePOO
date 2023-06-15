//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#include "Producto.h"

//Constructores

Producto::Producto(int _codigo, std::string _descripcion, double _precio, int _cantidad) : codigo(_codigo), descripcion(_descripcion), cantidad(_cantidad) {
    if(_precio > 0)
        precio = _precio;
    else
        precio = 1.0;
    
    if(_cantidad < 1 || _cantidad > 10)
        cantidad = 1;
}

Producto::Producto(int _codigo, std::string _descripcion, double _precio) : codigo(_codigo), descripcion(_descripcion), precio(_precio > 0 ? _precio : 1.0), cantidad(1) {}

//Función para calcular el subtotal
double Producto::getSubTotal() {
    return precio * cantidad;
}

//Función para calcular los impuestos
double Producto::getImpuestos() {
    return 0;
}

//Función para calcular el total
double Producto::getTotal() {
    return getSubTotal() + getImpuestos();
}
