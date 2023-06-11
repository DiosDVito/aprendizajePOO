#ifndef HABITACIONDELUXE_H
#define HABITACIONDELUXE_H

#include "habitacion.h"

class HabitacionDeluxe : public Habitacion {
public:
    bool checkin(const std::string& nombre, int adultos, int infantes, double credito) override;
    double getTarifaBase() const override;
};

#endif
