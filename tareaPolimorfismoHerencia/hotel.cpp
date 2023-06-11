#include "hotel.h"
#include <iostream>

Hotel::Hotel(const std::string& nombreHotel) : numHabitaciones(0), nombre(nombreHotel) {}

Hotel::~Hotel() {
    for (Habitacion* habitacion : habitaciones) {
        delete habitacion;
    }
}

int Hotel::checkin(const std::string& nombre, int adultos, int infantes, double credito, int tipoHabitacion) {
    if (numHabitaciones >= habitaciones.size()) {
        std::cout << "No hay habitaciones disponibles." << std::endl;
        return -1;
    }

    TipoHabitacion tipo = static_cast<TipoHabitacion>(tipoHabitacion - 1);
    Habitacion* habitacion = nullptr;

    for (Habitacion* habitacionExistente : habitaciones) {
        if (habitacionExistente->isDisponible()) {
            if ((tipo == TipoHabitacion::Junior && typeid(*habitacionExistente) == typeid(HabitacionJunior)) ||
                (tipo == TipoHabitacion::Suite && typeid(*habitacionExistente) == typeid(HabitacionSuite)) ||
                (tipo == TipoHabitacion::Deluxe && typeid(*habitacionExistente) == typeid(HabitacionDeluxe))) {
                habitacion = habitacionExistente;
                break;
            }
        }
    }

    if (habitacion == nullptr) {
        std::cout << "No hay habitaciones disponibles del tipo seleccionado." << std::endl;
        return -1;
    }

    if (habitacion->checkin(nombre, adultos, infantes, credito)) {
        return habitacion->getNumero();
    } else {
        std::cout << "No hay disponibilidad en el hotel o la capacidad de la habitacion es insuficiente." << std::endl;
        return -1;
    }
}


bool Hotel::checkout(int numeroHabitacion) {
    for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it) {
        if ((*it)->getNumero() == numeroHabitacion) {
            bool checkoutSuccess = (*it)->checkout();
            delete *it;
            habitaciones.erase(it);
            numHabitaciones--;
            return checkoutSuccess;
        }
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int numeroHabitacion, double cantidad) {
    for (Habitacion* habitacion : habitaciones) {
        if (habitacion->getNumero() == numeroHabitacion) {
            return habitacion->realizarCargo(cantidad);
        }
    }
    return false;
}

double Hotel::getTotalXTarifaBase() const {
    double total = 0.0;
    for (const Habitacion* habitacion : habitaciones) {
        total += habitacion->getTarifaBase();
    }
    return total;
}

void Hotel::imprimeOcupacion() const {
    std::cout << "Ocupacion en " << nombre << std::endl;
    for (const Habitacion* habitacion : habitaciones) {
        std::cout << habitacion->toString() << ",";
        if (dynamic_cast<const HabitacionJunior*>(habitacion) != nullptr) {
            std::cout << "Habitación Junior" << std::endl;
        } else if (dynamic_cast<const HabitacionSuite*>(habitacion) != nullptr) {
            std::cout << "Habitación Suite" << std::endl;
        } else if (dynamic_cast<const HabitacionDeluxe*>(habitacion) != nullptr) {
            std::cout << "Habitación Deluxe" << std::endl;
        }
    }
}

