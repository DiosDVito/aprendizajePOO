//Daniel Esparza Arizpe 
//Viernes 11 de junio 2023

#ifndef HABITACION_H
#define HABITACION_H

//Headers de clase habitacion
#include <iostream>
#include <string>

class habitacion {
protected:
    //Atributos de la clase habitacion
    int numero;
    std::string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;
    int capacidadMax;
public:
    habitacion();
    habitacion(int numHab); //Constructor
    virtual ~habitacion() {}; //Destructor
    int getNumero() const; //Getter
    int getCapacidadMaxima() const; //Getter
    bool estaDisponible() const; //Getter
    void checkin(const std::string nomHues, int numAdultos, int numInfantes, double creditoAbierto); //Declara la funcion checkin
    bool checkout();
    virtual double getTarifaBase() const;
    bool realizarCargo(double cantidad);
    virtual std::string toString() const;
    virtual int getTipo() const = 0;
};


#endif