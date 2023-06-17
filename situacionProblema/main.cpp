//Daniel Esparza Arizpe - A01637076
//Sabado 17 de junio 2023

#include "video.h"
#include "episodio.h"
#include "pelicula.h"
#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <sstream>
#include <cctype>
#include <fstream>



using namespace std;


int main() {
    fstream archivo("videos.txt");
    vector<Video*> videos;

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string tipo;
            getline(ss, tipo, ',');

            if (tipo == "c") {
                string id, titulo, duracion_str, genero, serie, numero_str;
                getline(ss, id, ',');
                getline(ss, titulo, ',');
                getline(ss, duracion_str, ',');
                getline(ss, genero, ',');
                getline(ss, serie, ',');
                getline(ss, numero_str, ',');

                int duracion = stoi(duracion_str);
                int numero = stoi(numero_str);

                videos.push_back(new Episodio(id, titulo, duracion, genero, serie, numero));
            }

            else if (tipo == "p") {
                string id, titulo, duracion_str, genero;
                getline(ss, id, ',');
                getline(ss, titulo, ',');
                getline(ss, duracion_str, ',');
                getline(ss, genero, ',');

                int duracion = stoi(duracion_str);

                videos.push_back(new Pelicula(id, titulo, duracion, genero));
            }
        }
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    //Menu
    int opcion = 9;
    while (opcion != 0) {
        cout << "===== BIENVENIDO A CISFI STREAMING SERVICES =====" << endl;
        cout << "1. Mostrar todo el catalogo con calificaciones" << endl;
        cout << "2. Calificar un video" << endl;
        cout << "3. Mostrar peliculas o capitulos con una calificacion mínima determinada" << endl;
        cout << "4. Mostrar peliculas o capitulos de un cierto genero" << endl;
        cout << "0. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Id, Nombre, Duracion, Genero, (Serie, Episodio), Calificacion"<<endl;
                for(Video* video : videos){
                    cout<< *video << endl;
                }
                break;
            case 2:
            {
                string videoID = "";
                bool videoEncontrado = false;
                cout << "Ingrese el ID del video a calificar: ";
                cin >> videoID;
                for(Video* video : videos) {
                    if (video->getId() == videoID) {
                        videoEncontrado = true;

                        int calificacion;
                        cout << "Ingrese la calificacion (1-5): ";
                        cin >> calificacion;

                        while (!cin || calificacion < 1 || calificacion > 5) {
                            cout << "Calificacion invalida. Ingrese un valor entero entre 1 y 5: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> calificacion;
                        }

                        video->calificar(calificacion);

                        cout << "Video calificado correctamente" << endl;
                        break;
                    }
                }

                    if (!videoEncontrado) {
                        cout << "No se encontro el ID." << endl;
                    }
                break;
            }
            case 3:
                {

                int opcion = 0;
                cout << "===== BUSCAR POR CALIFICACION MINIMA =====" << endl;
                cout << "1. Ver peliculas" << endl;
                cout << "2. Ver capitulos" << endl;
                cout << "3. Ver ambos" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion;
                while (!cin || opcion < 1 || opcion > 3) {
                    cout << "Opcion invalida. Ingrese un valor entre 1 y 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> opcion;
                }


                double calificacion=0.0;
                cout << "Ingrese la calificacion minima (1-5): ";
                cin >> calificacion;
                while (!cin || calificacion < 1 || calificacion > 5) {
                    cout << "Calificacion invalida. Debe ser entre 1 y 5: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> calificacion;
                }

                cout << "Id, Nombre, Calificacion"<<endl;
                for(Video* video : videos) { 
                    if (opcion == 1 && dynamic_cast<Pelicula*>(video)) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCal() << endl;
                        }
                    }
                    else if (opcion == 2 && dynamic_cast<Episodio*>(video)) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCal() << endl;
                        }
                    }
                    else if (opcion == 3) {
                        if (video->getCalificacion() >= calificacion) {
                            cout << video->imprimirCal() << endl;
                        }
                    }
                }
                break;
            }
            case 4:
    {
        int opcion = 0;
        cout << "===== BUSCAR POR GENERO =====" << endl;
        cout << "1. Ver peliculas" << endl;
        cout << "2. Ver capitulos" << endl;
        cout << "3. Ver ambos" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        while (!cin || opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Ingrese un valor entre 1 y 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> opcion;
        }

        string genero;
        cout << "Ingrese el genero: ";
        cin >> genero;

        bool found = false;

        cout << "Id, Nombre,  Genero, Calificacion"<<endl;
        // Mostrar películas o capítulos con una calificación mínima determinada
        for(Video* video : videos) { 
            if (opcion == 1 && dynamic_cast<Pelicula*>(video)) {
                if (video->getGenero() == genero) {
                    cout << video->imprimirGenero() << endl;
                    found = true;
                }
            }
            else if (opcion == 2 && dynamic_cast<Episodio*>(video)) {
                if (video->getGenero() == genero) {
                    cout << video->imprimirGenero() << endl;
                    found = true;
                }
            }
            else if (opcion == 3) {
                if (video->getGenero() == genero) {
                    cout << video->imprimirGenero() << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "No se encontraron videos con el genero " << genero << "." << endl;
        }

        break;
    }

            case 0:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opción invalida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    }
    
    return 0;
}