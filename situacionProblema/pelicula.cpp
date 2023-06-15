#include "Pelicula.h"

Pelicula::Pelicula(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero)
    : Video(codigo, titulo, duracion, genero) {}

void Pelicula::mostrarDetalles() const {
    std::cout << *this << std::endl;
}