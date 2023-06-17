//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#include "pelicula.h"
#include <string>
using namespace std;

Pelicula::Pelicula():Video(){}

Pelicula::Pelicula(string id, string nombre, int duracion, string genero):Video(id, nombre, duracion, genero){}

Pelicula::~Pelicula(){}

string Pelicula::imprimir(){
    return this->id + ", " + this->nombre + ", " + to_string(this->duracion) + ", " + this->genero + ", " + calSC();
}

