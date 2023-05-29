//Daniel Esparza Arizpe 
//Viernes 19 de mayo 2023

#include <iostream>
#include "habitacion.h"
#include "hotel.h"

void mostrarMenu() {
    std::cout << "===== HOTEL CISFI =====" << std::endl;
    std::cout << "1. Check-in" << std::endl;
    std::cout << "2. Check-out" << std::endl;
    std::cout << "3. Realizar cargo a habitación" << std::endl;
    std::cout << "4. Habitaciones ocupadas" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese la opción deseada: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    return opcion;
}

int main() {
    Hotel hotel("HOTEL CISFI", 5);

    int opcion;
    do {
        mostrarMenu();
        opcion = obtenerOpcion();

        if (opcion == 1) {
            std::string nombre;
            int numAdultos, numInfantes;
            double creditoAbierto;

            std::cout << "Ingrese el nombre del huésped: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);

            std::cout << "Ingrese el número de adultos: ";
            std::cin >> numAdultos;

            std::cout << "Ingrese el número de infantes: ";
            std::cin >> numInfantes;

            std::cout << "Ingrese el crédito abierto: ";
            std::cin >> creditoAbierto;

            int numHabitacion = hotel.checkin(nombre, numAdultos, numInfantes, creditoAbierto);
            if (numHabitacion != -1) {
                std::cout << "Check-in exitoso. Habitación asignada: #" << numHabitacion << std::endl;
            } else {
                std::cout << "El hotel está lleno. No se pudo realizar el check-in." << std::endl;
            }
        } else if (opcion == 2) {
            int numHabitacion;

            std::cout << "Ingrese el número de habitación a hacer check-out: ";
            std::cin >> numHabitacion;

            bool checkoutExitoso = hotel.checkout(numHabitacion);
            if (checkoutExitoso) {
                std::cout << "Check-out exitoso de la habitación #" << numHabitacion << std::endl;
            } else {
                std::cout << "No se pudo realizar el check-out de la habitación #" << numHabitacion << std::endl;
            }
        } else if (opcion == 3) {
            int numHabitacion;
            double cantidad;

            std::cout << "Ingrese el número de habitación: ";
            std::cin >> numHabitacion;

            std::cout << "Ingrese la cantidad a cargar: ";
            std::cin >> cantidad;

            bool cargoExitoso = hotel.realizarCargosHabitacion(numHabitacion, cantidad);
            if (cargoExitoso) {
                std::cout << "Cargo exitoso en la habitación #" << numHabitacion << std::endl;
            } else {
                std::cout << "No se pudo realizar el cargo en la habitación #" << numHabitacion << std::endl;
            }
        } else if (opcion == 4) {
            hotel.imprimeOcupacion();
        } else if (opcion == 0) {
            std::cout << "Saliendo del programa." << std::endl;
        } else {
            std::cout << "Opción inválida. Por favor, seleccione una opción válida." << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
