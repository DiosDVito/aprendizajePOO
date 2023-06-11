#include "habitacionSuite.h"

bool HabitacionSuite::checkin(const std::string& nombre, int adultos, int infantes, double credito) {
    if (disponible && adultos + infantes <= 6) {
        this->nombre = nombre;
        this->adultos = adultos;
        this->infantes = infantes;
        this->credito = credito;
        cargo = 0.0;
        disponible = false;
        return true;
    }
    return false;
}

double HabitacionSuite::getTarifaBase() const {
    return Habitacion::getTarifaBase() * 1.3;
}
