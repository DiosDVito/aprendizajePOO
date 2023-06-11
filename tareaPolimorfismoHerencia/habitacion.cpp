#include "habitacion.h"

Habitacion::Habitacion() : numero(0), nombre(""), adultos(0), infantes(0), credito(0.0), cargo(0.0), disponible(true) {}

Habitacion::Habitacion(int numero) : numero(numero), nombre(""), adultos(0), infantes(0), credito(0.0), cargo(0.0), disponible(true) {}

int Habitacion::getNumero() const {
    return numero;
}

bool Habitacion::isDisponible() const {
    return disponible;
}

bool Habitacion::checkin(const std::string& nombre, int adultos, int infantes, double credito) {
    if (disponible) {
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

bool Habitacion::checkout() {
    if (!disponible) {
        this->nombre = "";
        this->adultos = 0;
        this->infantes = 0;
        this->credito = 0.0;
        this->cargo = 0.0;
        disponible = true;
        return true;
    }
    return false;
}

double Habitacion::getTarifaBase() const {
    return 450.0 * adultos + 150.0 * infantes;
}

bool Habitacion::realizarCargo(double cantidad) {
    if (cantidad > 0.0 && cantidad <= credito) {
        cargo += cantidad;
        credito -= cantidad;
        return true;
    }
    return false;
}

std::string Habitacion::toString() const {
    return std::to_string(numero) + ",Huesped:" + nombre + ",Tarifa Base:" + std::to_string(getTarifaBase()) +
           ",Credito:" + std::to_string(credito) + ",Cargos:" + std::to_string(cargo);
}
