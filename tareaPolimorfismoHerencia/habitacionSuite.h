#ifndef HABITACIONSUITE_H
#define HABITACIONSUITE_H

#include "habitacion.h"

class HabitacionSuite : public Habitacion {
public:
    bool checkin(const std::string& nombre, int adultos, int infantes, double credito) override;
    double getTarifaBase() const override;
};

#endif
