//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#include <iostream>
#include "producto.h"
#include "productoIVA.h"
#include "productoIVAIEPS.h"
#include "carrito.h"

int main(){
    Carrito carrito;
    carrito.agregarProducto(new Producto(1,"Tortilla",15.5));
    carrito.agregarProducto(new Producto(2,"Bolillo",8,5));
    carrito.agregarProducto(new ProductoIVA(3,"Detergente",40));
    carrito.agregarProducto(new ProductoIVA(4,"Queso",50,4));
    carrito.agregarProducto(new ProductoIVAIEPS(5,"Refresco",60,1500));
    carrito.agregarProducto(new ProductoIVAIEPS(6,"Bebida energetica",50,5,250));
    std::cout<<carrito<<std::endl;
    return 0;
}