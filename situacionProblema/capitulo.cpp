#include "capitulo.h"

Capitulo::Capitulo(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero,
    const std::string& serie)
    : Video(codigo, titulo, duracion, genero), serie(serie) {}
std::ostream& operator<<(std::ostream &out, const Capitulo &c) {
    out << static_cast<const Video&>(c); 
    out << "," << c.serie;
    return out;
}
void Capitulo::mostrarDetalles() const {
    std::cout << *this << std::endl; 
}
