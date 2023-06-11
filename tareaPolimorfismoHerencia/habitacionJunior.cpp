//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#include "habitacionJunior.h"
#include <sstream>

habitacionJunior::habitacionJunior(int numHab) : habitacion(numHab) {
    capacidadMax = 4; //Capacidad maxima de la habitacion Junior
}

double habitacionJunior::getTarifaBase() const {
    return 1.2 * habitacion::getTarifaBase(); // Incrementa la tarifa base en un 20%
}

std::string habitacionJunior::toString() const {
    std::ostringstream oss;
    oss << habitacion::toString() << ",Habitación Junior";
    return oss.str();
}

int habitacionJunior::getTipo() const {
    return 1; // Retorna 1 para habitación Junior
}