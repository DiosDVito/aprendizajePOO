//Daniel Esparza Arizpe A01637076
//Viernes 12 de junio 2023

#ifndef PRODUCTOIVAIEPS_H
#define PRODUCTOIVAIEPS_H

#include "productoIVA.h"

class ProductoIVAIEPS : public ProductoIVA {
    protected:
        int ml; //Cuantos mililitros trae la botella
        const double IEPSxLT = 1.5086; //Valor del IEPS por Lt.
    public:
        ProductoIVAIEPS(int, std::string, double, int); //constructor con parámetros sin cantidad
        ProductoIVAIEPS(int, std::string, double, int, int); //constructor con parámetros con cantidad
        double getIEPS(); //nuevo método para obtener el IEPS
        double getImpuestos() override; //sobrescritura del método getImpuestos
        double getTotal() override; //sobrescritura del método getTotal
};

#endif 
