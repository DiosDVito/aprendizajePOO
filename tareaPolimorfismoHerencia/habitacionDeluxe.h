//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#ifndef HABITACIONDELUXE_H
#define HABITACIONDELUXE_H
#include "habitacion.h"

class habitacionDeluxe:public habitacion{
    public:
        habitacionDeluxe(int numHab);
        double getTarifaBase() const override;
        std::string toString() const override;
        int getTipo() const override;
};


#endif