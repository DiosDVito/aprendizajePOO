//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#ifndef CARRITO_H
#define CARRITO_H

#include <vector>
#include "producto.h"

class Carrito {
    private:
        std::vector<Producto*> productos;
    public:
        void agregarProducto(Producto* producto);
        double getSubtotalCuenta()const;
        double getImpuestosCuenta()const;
        double getTotalCuenta() const;
        friend std::ostream& operator<<(std::ostream& os, const Carrito& carrito);
};


#endif


