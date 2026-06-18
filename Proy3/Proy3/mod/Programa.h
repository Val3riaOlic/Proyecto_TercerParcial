#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "ResultadoPrograma.h"

class Programa {
public:
    virtual ResultadoPrograma ejecutar() = 0;
    virtual ~Programa() {}
};

#endif
