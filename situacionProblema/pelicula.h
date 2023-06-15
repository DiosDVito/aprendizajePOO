#ifndef PELICULA_H
#define PELICULA_H

#include "video.h"

class Pelicula : public Video {
public:
    Pelicula(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero);
    void mostrarDetalles() const override;
};


#endif