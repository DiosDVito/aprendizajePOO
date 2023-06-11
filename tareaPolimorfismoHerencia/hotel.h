//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "habitacion.h"
#include "habitacionDeluxe.h"
#include "habitacionJunior.h"
#include "habitacionSuite.h"

class Hotel {
private:
    std::string nombre;
    std::vector<habitacion*> habitaciones;

public:
    Hotel(const std::string& nombreHotel, int numHabJunior, int numHabSuite, int numHabDeluxe);
    int checkin(const std::string& nombreHuesped, int numAdultos, int numInfantes, double creditoAbierto);
    bool checkout(int numHabitacion);
    bool realizarCargosHabitacion(int numHabitacion, double cargo);
    double getTotalXTarifaBase() const;
    void imprimeOcupacion() const;
    double getIngresosPorTarifas() const;
};

#endif  // HOTEL_H
