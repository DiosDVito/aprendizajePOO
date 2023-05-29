//Daniel Esparza Arizpe 
//Viernes 19 de mayo 2023

#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "habitacion.h"

class Hotel {
private:
    std::string nombre;
    std::vector<habitacion> habitaciones;

public:
    Hotel(const std::string& nombreHotel, int numHabitaciones);
    int checkin(const std::string& nombreHuesped, int numAdultos, int numInfantes, double creditoAbierto);
    bool checkout(int numHabitacion);
    bool realizarCargosHabitacion(int numHabitacion, double cargo);
    double getTotalXTarifaBase() const;
    void imprimeOcupacion() const;
};

#endif  // HOTEL_H
