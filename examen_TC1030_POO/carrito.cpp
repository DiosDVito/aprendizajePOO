//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#include "Carrito.h"

void Carrito::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

double Carrito::getSubtotalCuenta() const {
    double subtotal = 0.0;
    for(auto& producto : productos) {
        subtotal += producto->getSubTotal();
    }
    return subtotal;
}

double Carrito::getImpuestosCuenta() const {
    double impuestos = 0.0;
    for(auto& producto : productos) {
        impuestos += producto->getImpuestos();
    }
    return impuestos;
}

double Carrito::getTotalCuenta() const {
    return getSubtotalCuenta() + getImpuestosCuenta();
}

std::ostream& operator<<(std::ostream& os, const Carrito& carrito) {
    os << "Gracias por comprar con nosotros\n";
    os << "El subtotal sin impuestos es $" << carrito.getSubtotalCuenta() << "\n";
    os << "El total de impuestos a pagar es $" << carrito.getImpuestosCuenta() << "\n";
    os << "El total de su cuenta es $" << carrito.getTotalCuenta() << "\n";
    return os;
}
