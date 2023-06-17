//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "video.h"
using namespace std;

class Pelicula:public Video{
    
    public:
        Pelicula();
        Pelicula(string, string, int, string);
        ~Pelicula();

        string imprimir();

};
#endif