#include "hotel.h"
#include <iostream>

int main() {
    Hotel* hotel = nullptr;

    int opcion;
    do {
        std::cout << "==== Menu ====" << std::endl;
        std::cout << "1. Crear Hotel" << std::endl;
        std::cout << "2. Hacer check-in" << std::endl;
        std::cout << "3. Hacer check-out" << std::endl;
        std::cout << "4. Realizar cargos a habitacion" << std::endl;
        std::cout << "5. Ingresos por tarifas" << std::endl;
        std::cout << "6. Generar reporte de ocupacion" << std::endl;
        std::cout << "7. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            if (hotel != nullptr) {
                delete hotel;
            }

            std::string nombre;
            int numJunior, numSuite, numDeluxe;

            std::cout << "Nombre del hotel: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Numero de habitaciones Junior: ";
            std::cin >> numJunior;
            std::cout << "Numero de habitaciones Suite: ";
            std::cin >> numSuite;
            std::cout << "Numero de habitaciones Deluxe: ";
            std::cin >> numDeluxe;

            hotel = new Hotel(nombre);

            for (int i = 0; i < numJunior; i++) {
                hotel->checkin("", 0, 0, 0.0, 1);
            }
            for (int i = 0; i < numSuite; i++) {
                hotel->checkin("", 0, 0, 0.0, 2);
            }
            for (int i = 0; i < numDeluxe; i++) {
                hotel->checkin("", 0, 0, 0.0, 3);
            }
        } else if (opcion == 2) {
            if (hotel == nullptr) {
                std::cout << "No se ha creado un hotel." << std::endl;
            } else {
                std::string nombre;
                int adultos, infantes, tipoHabitacion;

                std::cout << "Nombre del huesped: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Numero de adultos: ";
                std::cin >> adultos;
                std::cout << "Numero de infantes: ";
                std::cin >> infantes;
                std::cout << "Tipo de habitacion (1=Junior, 2=Suite, 3=Deluxe): ";
                std::cin >> tipoHabitacion;

                int numHabitacion = hotel->checkin(nombre, adultos, infantes, 0.0, tipoHabitacion);
                if (numHabitacion != -1) {
                    std::cout << "Check-in exitoso. Habitacion asignada: " << numHabitacion << std::endl;
                }
            }
        } else if (opcion == 3) {
            if (hotel == nullptr) {
                std::cout << "No se ha creado un hotel." << std::endl;
            } else {
                int numHabitacion;
                std::cout << "Numero de habitacion: ";
                std::cin >> numHabitacion;

                if (hotel->checkout(numHabitacion)) {
                    std::cout << "Check-out exitoso." << std::endl;
                } else {
                    std::cout << "La habitacion no existe o no estaba ocupada." << std::endl;
                }
            }
        } else if (opcion == 4) {
            if (hotel == nullptr) {
                std::cout << "No se ha creado un hotel." << std::endl;
            } else {
                int numHabitacion;
                double cantidad;
                std::cout << "Numero de habitacion: ";
                std::cin >> numHabitacion;
                std::cout << "Cantidad a cargar: ";
                std::cin >> cantidad;

                if (hotel->realizarCargosHabitacion(numHabitacion, cantidad)) {
                    std::cout << "Cargo realizado exitosamente." << std::endl;
                } else {
                    std::cout << "La habitacion no existe o no estaba ocupada, o el cargo excede el credito disponible." << std::endl;
                }
            }
        } else if (opcion == 5) {
            if (hotel == nullptr) {
                std::cout << "No se ha creado un hotel." << std::endl;
            } else {
                double total = hotel->getTotalXTarifaBase();
                std::cout << "Total recaudado por tarifa base: " << total << std::endl;
            }
        } else if (opcion == 6) {
            if (hotel == nullptr) {
                std::cout << "No se ha creado un hotel." << std::endl;
            } else {
                hotel->imprimeOcupacion();
            }
        } else if (opcion == 7) {
            std::cout << "Saliendo del programa..." << std::endl;
        } else {
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }

        std::cout << std::endl;
    } while (opcion != 7);

    if (hotel != nullptr) {
        delete hotel;
    }

    return 0;
}
