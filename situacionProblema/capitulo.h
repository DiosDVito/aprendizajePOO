#ifndef CAPITULO_H
#define CAPITULO_H

#include "video.h"

class Capitulo : public Video {
    std::string serie;
    int numCap;

public:
    Capitulo(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero,
        const std::string& serie);
    friend std::ostream& operator<<(std::ostream &out, const Capitulo &c);
    void mostrarDetalles() const override;

};


#endif

