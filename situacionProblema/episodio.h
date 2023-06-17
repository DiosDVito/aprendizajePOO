//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#ifndef EPISODIO_H
#define EPISODIO_H
#include <string>
#include "video.h"
using namespace std;

class Episodio:public Video{
    private:
        int episodio;
        string serie;
    public:
        Episodio();
        Episodio(string, string, int, string, string, int);
        ~Episodio();

        string imprimir();

};
#endif