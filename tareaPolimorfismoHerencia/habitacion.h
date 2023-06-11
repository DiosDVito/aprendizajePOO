#ifndef HABITACION_H
#define HABITACION_H

#include <string>

class Habitacion {
protected:
    int numero;
    std::string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;

public:
    Habitacion();
    explicit Habitacion(int numero);

    int getNumero() const;
    bool isDisponible() const;
    virtual bool checkin(const std::string& nombre, int adultos, int infantes, double credito);
    virtual bool checkout();
    virtual double getTarifaBase() const;
    virtual bool realizarCargo(double cantidad);
    std::string toString() const;
};

#endif
