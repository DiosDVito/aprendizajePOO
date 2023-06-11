//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#include "habitacionDeluxe.h"
#include <sstream>

habitacionDeluxe::habitacionDeluxe(int numHab) : habitacion(numHab) {
    capacidadMax = 8; // Capacidad maxima de la habitacion Deluxe
}

double habitacionDeluxe::getTarifaBase() const {
    return 1.5 * habitacion::getTarifaBase(); // Incrementa la tarifa base en un 50%
}

std::string habitacionDeluxe::toString() const {
    std::ostringstream oss;
    oss << habitacion::toString() << ",Habitación Deluxe";
    return oss.str();
}

int habitacionDeluxe::getTipo() const {
    return 3; // Retorna 3 para habitación Deluxe
}