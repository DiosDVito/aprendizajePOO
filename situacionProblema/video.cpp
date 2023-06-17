//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#include "video.h"
#include <string>
using namespace std;

Video::Video():Video("","",0,""){}

Video::Video(string id, string nombre, int duracion, string genero){
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;

    sumcal = 0;
    numcal = 0;
    calificacion = 0;
}

Video::~Video(){}

void Video::calificar(int cal){
    this->sumcal += cal;
    this->numcal++;
    this->calcCalificacionPromedio();
}

void Video::calcCalificacionPromedio(){
    if (this->numcal !=0){
        this->calificacion = (double)this->sumcal/this->numcal;
    }
}

string Video::getId(){
    return this->id;
}

string Video::getGenero(){
    return this->genero;
}

double Video::getCalificacion(){
    return this->calificacion;
}


string Video::calSC(){
    if (this->sumcal != 0)
    {
        return to_string(this->calificacion);
    }else{
        return "SC";
    }
}

string Video::imprimirGenero(){
    return   this->id + ", " + this->nombre + ", " + this->genero + ", " + calSC();
}

string Video::imprimirCal(){
    return   this->id + ", " + this->nombre + ", " + calSC();
}

