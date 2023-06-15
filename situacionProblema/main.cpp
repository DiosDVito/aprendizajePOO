#include "Pelicula.h"
#include "Capitulo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<Video*> cargar_videos() {
    std::ifstream file("videos.txt");
    std::string line;
    std::vector<Video*> videos;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> seglist;

        while (std::getline(ss, segment, ',')) {
            seglist.push_back(segment);
        }

        if (seglist[0] == "p") {
            videos.push_back(new Pelicula(seglist[1], seglist[2], std::stoi(seglist[3]), seglist[4]));
        } else if (seglist[0] == "c") {
            videos.push_back(new Capitulo(seglist[1], seglist[2], std::stoi(seglist[3]), seglist[4], seglist[5]));
        }
    }

    file.close();
    return videos;
}

void mostrarCatalogo(const std::vector<Video*>& videos) {
    for (const auto& video : videos) {
        video->mostrarDetalles();
    }
}

void calificar_video(std::vector<Video*>& videos) {
    std::string codigo;
    std::cout << "Ingresa el codigo del video: ";
    std::cin >> codigo;
    
    for (const auto& video : videos) {
        if (video->obtener_codigo() == codigo) {
            int calificacion;
            std::cout << "Ingresa tu calificacion (1-5): ";
            std::cin >> calificacion;
            video->agregar_calificacion(calificacion);
            return;
        }
    }

    std::cout << "No se encontro el video con el codigo ingresado.\n";
}

void mostrar_videos_calificacion_minima(const std::vector<Video*>& videos) {
    int opcion;
    std::cout << "Película = 1, Capítulo = 2, Ambos = 3. Selecciona una opcion: ";
    std::cin >> opcion;
    float calificacion_minima;
    std::cout << "Ingresa la calificacion minima: ";
    std::cin >> calificacion_minima;

    bool encontrado = false;
    for (const auto& video : videos) {
        float calificacion_promedio = video->calcular_calificacion_promedio();
        if (calificacion_promedio >= calificacion_minima) {
            if ((opcion == 1 && dynamic_cast<Pelicula*>(video) != nullptr)
                || (opcion == 2 && dynamic_cast<Capitulo*>(video) != nullptr)
                || opcion == 3) {
                std::cout << *video << "\n";
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        std::cout << "No encontrado\n";
    }
}

void mostrar_videos_por_genero(const std::vector<Video*>& videos) {
    int opcion;
    std::cout << "Película = 1, Capítulo = 2, Ambos = 3. Selecciona una opcion: ";
    std::cin >> opcion;
    std::string genero;
    std::cout << "Ingresa el genero: ";
    std::cin >> genero;

    bool encontrado = false;
    for (const auto& video : videos) {
        if (video->obtener_genero() == genero) {
            if ((opcion == 1 && dynamic_cast<Pelicula*>(video) != nullptr)
                || (opcion == 2 && dynamic_cast<Capitulo*>(video) != nullptr)
                || opcion == 3) {
                std::cout << *video << "\n";
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        std::cout << "No encontrado\n";
    }
}

int main() {
    std::vector<Video*> videos = cargar_videos();
    int opcion;

    do {
        std::cout << "1. Mostrar todo el catalogo con calificaciones.\n";
        std::cout << "2. Calificar un video.\n";
        std::cout << "3. Mostrar peliculas o capitulos con una calificacion minima determinada.\n";
        std::cout << "4. Mostrar peliculas o capitulos de un cierto genero.\n";
        std::cout << "0. Salir.\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if(opcion == 1) {
            mostrarCatalogo(videos);
        } else if(opcion == 2) {
            calificar_video(videos);
        } else if(opcion == 3) {
            mostrar_videos_calificacion_minima(videos);
        } else if(opcion == 4) {
            mostrar_videos_por_genero(videos);
        } else if(opcion == 0) {
            std::cout << "Adios!\n";
        } else {
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    for (auto& video : videos) {
        delete video;
    }

    return 0;
}