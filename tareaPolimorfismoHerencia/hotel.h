#ifndef HOTEL_H
#define HOTEL_H

#include "habitacion.h"
#include "habitacionJunior.h"
#include "habitacionSuite.h"
#include "habitacionDeluxe.h"

#include <string>
#include <vector>

class Hotel {
private:
    std::vector<Habitacion*> habitaciones;
    int numHabitaciones;
    std::string nombre;

public:
    explicit Hotel(const std::string& nombreHotel);
    ~Hotel();

    int checkin(const std::string& nombre, int adultos, int infantes, double credito, int tipoHabitacion);
    bool checkout(int numeroHabitacion);
    bool realizarCargosHabitacion(int numeroHabitacion, double cantidad);
    double getTotalXTarifaBase() const;
    void imprimeOcupacion() const;
    enum class TipoHabitacion {
    Junior,
    Suite,
    Deluxe
};

};

#endif
