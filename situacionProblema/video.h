#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <iostream>

class Video {
protected:
    std::string codigo;
    std::string titulo;
    int duracion;
    std::string genero;
    std::vector<int> calificaciones;

public:
    Video(const std::string& codigo, const std::string& titulo, int duracion, const std::string& genero);
    virtual ~Video() = default;

    std::string obtener_codigo() const;
    std::string obtener_titulo() const;
    std::string obtener_genero() const;
    int obtener_duracion() const;
    void agregar_calificacion(int calificacion);
    float calcular_calificacion_promedio() const;
    friend std::ostream& operator<<(std::ostream& os, const Video& video);
    virtual void mostrarDetalles() const = 0;

};


#endif