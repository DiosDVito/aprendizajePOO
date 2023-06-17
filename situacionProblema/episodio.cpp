//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#include "episodio.h"
#include <string>
using namespace std;

Episodio::Episodio():Video(){
    episodio = 0;
    serie = "";
}

Episodio::Episodio(string id, string nombre, int duracion, string genero, string serie, int episodio):Video(id, nombre, duracion, genero){
    this->episodio = episodio;
    this->serie = serie;
}

Episodio::~Episodio(){}

string Episodio::imprimir(){
    return this->id + ", " + this->nombre + ", " + to_string(this->duracion) + ", " + this->genero + ", " + this->serie + " T" + to_string(this->episodio) + ", " + calSC();
}
