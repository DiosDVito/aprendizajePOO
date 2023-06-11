#include "habitacionDeluxe.h"

bool HabitacionDeluxe::checkin(const std::string& nombre, int adultos, int infantes, double credito) {
    if (disponible && adultos + infantes <= 8) {
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

double HabitacionDeluxe::getTarifaBase() const {
    return Habitacion::getTarifaBase() * 1.5;
}
