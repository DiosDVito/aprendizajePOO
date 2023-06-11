//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#include "habitacionSuite.h"
#include <sstream>

habitacionSuite::habitacionSuite(int numHab) : habitacion(numHab) {
    capacidadMax = 6; //Capacidad maxima de la habitacion Suite
}

double habitacionSuite::getTarifaBase() const {
    return 1.3 * habitacion::getTarifaBase(); // Incrementa la tarifa base en un 30%
}

std::string habitacionSuite::toString() const {
    std::ostringstream oss;
    oss << habitacion::toString() << ",Habitación Suite";
    return oss.str();
}

int habitacionSuite::getTipo() const {
    return 2; // Retorna 2 para habitación Suite
}