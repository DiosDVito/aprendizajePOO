//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#include "ProductoIVAIEPS.h"

//Constructores
ProductoIVAIEPS::ProductoIVAIEPS(int _codigo, std::string _descripcion, double _precio, int _ml) : ProductoIVA(_codigo, _descripcion, _precio), ml(_ml) {}

ProductoIVAIEPS::ProductoIVAIEPS(int _codigo, std::string _descripcion, double _precio, int _cantidad, int _ml) : ProductoIVA(_codigo, _descripcion, _precio, _cantidad), ml(_ml) {}

//Metodo para calcular el IEPS
double ProductoIVAIEPS::getIEPS() {
    return (ml / 1000.0) * IEPSxLT * cantidad;
}

double ProductoIVAIEPS::getImpuestos() {
    return ProductoIVA::getImpuestos() + getIEPS();
}

double ProductoIVAIEPS::getTotal() {
    return getSubTotal() + getImpuestos();
}
