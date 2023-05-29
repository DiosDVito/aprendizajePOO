//Daniel Esparza Arizpe 
//Viernes 19 de mayo 2023

#include "hotel.h"

Hotel::Hotel(const std::string& nombreHotel, int numHabitaciones) : nombre(nombreHotel)
{
    // Inicializar habitaciones
    for (int i = 0; i < numHabitaciones; i++) {
        int numeroHabitacion = 100 + i;
        habitaciones.push_back(habitacion(numeroHabitacion));
    }
}

int Hotel::checkin(const std::string& nombreHuesped, int numAdultos, int numInfantes, double creditoAbierto)
{
    for (habitacion& h : habitaciones) {
        if (h.estaDisponible()) {
            h.checkin(nombreHuesped, numAdultos, numInfantes, creditoAbierto);
            return h.getNumero();
        }
    }
    return -1; // El hotel está lleno
}

bool Hotel::checkout(int numHabitacion)
{
    for (habitacion& h : habitaciones) {
        if (h.getNumero() == numHabitacion) {
            return h.checkout();
        }
    }
    return false; // Habitación no encontrada
}

bool Hotel::realizarCargosHabitacion(int numHabitacion, double cantidad)
{
    for (habitacion& h : habitaciones) {
        if (h.getNumero() == numHabitacion) {
            return h.realizarCargo(cantidad);
        }
    }
    return false; // Habitación no encontrada
}

double Hotel::getTotalXTarifaBase() const
{
    double total = 0.0;
    for (const habitacion& h : habitaciones) {
        if (!h.estaDisponible()) {
            total += h.getTarifaBase();
        }
    }
    return total;
}

void Hotel::imprimeOcupacion() const
{
    std::cout << "Habitaciones ocupadas: " << nombre << std::endl;
    for (const habitacion& h : habitaciones) {
        if (!h.estaDisponible()) {
            std::cout << h.toString() << std::endl;
        }
    }
}
