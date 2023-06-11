//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#ifndef HABITACIONJUNIOR_H
#define HABITACIONJUNIOR_H
#include "habitacion.h"

class habitacionJunior:public habitacion{
    public:
        habitacionJunior(int numHab);
        double getTarifaBase() const override;
        std::string toString() const override;
        int getTipo() const override;
    
};


#endif