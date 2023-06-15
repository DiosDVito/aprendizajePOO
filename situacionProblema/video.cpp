#include "Video.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <numeric>

Video::Video(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero)
    : codigo(codigo), titulo(titulo), duracion(duracion), genero(genero) {}

std::string Video::obtener_codigo() const {
    return codigo;
}

std::string Video::obtener_titulo() const {
    return titulo;
}

std::string Video::obtener_genero() const {
    return genero;
}

int Video::obtener_duracion() const {
    return duracion;
}

void Video::agregar_calificacion(int calificacion) {
    if (calificacion < 1 || calificacion > 5) {
        std::cout << "La calificacion debe estar en el rango de 1 a 5" << std::endl;
    }
    calificaciones.push_back(calificacion);
}

float Video::calcular_calificacion_promedio() const {
    return std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / calificaciones.size();
}

std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << video.codigo << "," << video.titulo << "," << video.duracion << "," << video.genero << ",";
    if (video.calificaciones.empty()) {
        os << "SC";
    } else {
        os << video.calcular_calificacion_promedio();
    }
    return os;
}