//Daniel Esparza Arizpe 
//Viernes 19 de mayo 2023

#ifndef HABITACION_H
#define HABITACION_H

//Headers de clase habitacion
#include <iostream>
#include <string>

class habitacion {
private:
    //Atributos de la clase habitacion
    int numero;
    std::string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;
public:
    habitacion(int numHab); //Constructor
    int getNumero() const; //Getter
    bool estaDisponible() const; //Getter
    void checkin(const std::string nomHues, int numAdultos, int numInfantes, double creditoAbierto); //Declara la funcion checkin
    bool checkout();
    double getTarifaBase() const;
    bool realizarCargo(double cantidad);
    std::string toString() const;

};


#endif