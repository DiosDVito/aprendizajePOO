//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#ifndef HABITACIONSUITE_H
#define HABITACIONSUITE_H
#include "habitacion.h"

class habitacionSuite:public habitacion{
    public:
        habitacionSuite(int numHab);
        double getTarifaBase() const override;
        std::string toString() const override;
        int getTipo() const override;
};


#endif