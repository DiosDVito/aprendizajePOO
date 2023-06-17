//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>
using namespace std;

class Video{
    protected:
        string id;
        string nombre;
        int duracion;
        string genero;

        int sumcal;
        int numcal;
        double calificacion;

    public:
        Video();
        Video(string, string, int, string);
        ~Video();

        void calificar(int);
        void calcCalificacionPromedio();
        virtual string imprimir()=0;
        string imprimirCal();
        string imprimirGenero();
        string calSC();

        string getId();
        double getCalificacion();
        string getGenero();
    
    friend ostream& operator<< (ostream& os, Video& vid){
        os << vid.imprimir() ;
        return os;
        }
    
};
#endif