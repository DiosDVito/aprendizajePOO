#ifndef HABITACIONJUNIOR_H
#define HABITACIONJUNIOR_H

#include "habitacion.h"

class HabitacionJunior : public Habitacion {
public:
    bool checkin(const std::string& nombre, int adultos, int infantes, double credito) override;
    double getTarifaBase() const override;
};

#endif
