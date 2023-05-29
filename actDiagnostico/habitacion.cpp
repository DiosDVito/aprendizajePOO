//Daniel Esparza Arizpe 
//Viernes 19 de mayo 2023

//Implementación de la clase habitacion

#include "habitacion.h"
#include <sstream>



//Constructor
habitacion::habitacion(int numHab){
    numero = numHab;
    disponible = true;
    nombre = "";
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
}

//Getters
int habitacion::getNumero() const {
    return numero;
}
bool habitacion::estaDisponible() const {
    return disponible;
}

//Funcion check-in
void habitacion::checkin(const std::string nomHues, int numAdultos, int numInfantes, double creditoAbierto){
    nombre = nomHues;
    adultos = numAdultos;
    infantes = numInfantes;
    credito = creditoAbierto;
    disponible = false;
    cargo = 0;
}

//Funcion check-out

bool habitacion::checkout(){
    if (disponible) {
        return false; //La habitacion esta desocupada, no hay necesidad de hacer check-out
    }

    nombre = "";
    adultos = 0;
    infantes = 0;
    credito = 0;
    disponible = true;
    cargo = 0;


    return true;
}

//Funcion getTarifaBase

double habitacion::getTarifaBase() const{
    double tarifaAdulto = 450;
    double tarifaInfante = 150;
    double tarifaBase = adultos * tarifaAdulto + infantes * tarifaInfante;
    return tarifaBase;
}

//Funcion realizarCargo

bool habitacion::realizarCargo(double cantidad){
    if (cantidad <= 0.0 || cantidad > credito - cargo){
        return false; //No tiene credito suficiente
    }
    
    cargo += cantidad;
    return true; //Se realizó exitosamente
}

//Funcion toString (aqui si tuve que buscar en internet alguna forma de hacerlo ya que no se me ocurria y me salio esta)
std::string habitacion::toString() const {
    std::ostringstream oss;
    oss << numero << ",Huesped:" << nombre << ",Tarifa Base:" << (adultos * 450.0 + infantes * 150.0) << ",Crédito:" << credito << ",Cargos:" << cargo; //No podía llamar la funcion getTarifaBase asi que lo tuve que hacer de esta manera.
    return oss.str();
}