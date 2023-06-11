//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#include "hotel.h"

Hotel::Hotel(const std::string& nombreHotel, int numHabJunior, int numHabSuite, int numHabDeluxe) : nombre(nombreHotel)
{
    for (int i = 0; i < numHabJunior; i++) {
        int numeroHabitacion = 100 + i;
        habitaciones.push_back(new habitacionJunior(numeroHabitacion));
    }
    for (int i = 0; i < numHabSuite; i++) {
        int numeroHabitacion = 100 + numHabJunior + i;
        habitaciones.push_back(new habitacionSuite(numeroHabitacion));
    }
    for (int i = 0; i < numHabDeluxe; i++) {
        int numeroHabitacion = 100 + numHabJunior + numHabSuite + i;
        habitaciones.push_back(new habitacionDeluxe(numeroHabitacion));
    }
}


int Hotel::checkin(const std::string& nombreHuesped, int numAdultos, int numInfantes, double creditoAbierto)
{
    int tipoHabitacion;
    std::cout << "¿Qué tipo de habitación le gustaría? 1=Junior, 2=Suite, 3=Deluxe: ";
    std::cin >> tipoHabitacion;

    for (habitacion* h : habitaciones) {
        if (h->estaDisponible()&& h->getTipo() == tipoHabitacion) {
            // Comprueba si la capacidad de la habitación es suficiente
            if(h->getCapacidadMaxima() < numAdultos + numInfantes){
                std::cout << "Lo siento, este tipo de habitación no puede acomodar a todos los huéspedes." << std::endl;
                std::cout << "Por favor, intente con otro tipo de habitación o haga reservaciones separadas." << std::endl;
                return -1;
            }

            // Realiza el check-in si la capacidad de la habitación es suficiente
            h->checkin(nombreHuesped, numAdultos, numInfantes, creditoAbierto);
            return h->getNumero();
        }
    }

    std::cout << "Lo sentimos, todas nuestras habitaciones de este tipo están ocupadas en este momento." << std::endl;
    return -1;
}


bool Hotel::checkout(int numHabitacion)
{
    for (habitacion* h : habitaciones) {
        if (h->getNumero() == numHabitacion) {
            return h->checkout();
        }
    }
    return false; // Habitación no encontrada
}

bool Hotel::realizarCargosHabitacion(int numHabitacion, double cantidad)
{
    for (habitacion* h : habitaciones) {
        if (h->getNumero() == numHabitacion) {
            return h->realizarCargo(cantidad);
        }
    }
    return false; // Habitación no encontrada
}

double Hotel::getTotalXTarifaBase() const
{
    double total = 0.0;
    for (const habitacion* h : habitaciones) {
        if (!h->estaDisponible()) {
            total += h->getTarifaBase();
        }
    }
    return total;
}

void Hotel::imprimeOcupacion() const
{
    std::cout << "Habitaciones ocupadas: " << nombre << std::endl;
    for (const habitacion* h : habitaciones) {
        if (!h->estaDisponible()) {
            std::cout << h->toString() << std::endl;
        }
    }
}

