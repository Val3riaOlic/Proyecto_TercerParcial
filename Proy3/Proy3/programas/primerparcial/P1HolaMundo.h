#ifndef P1HOLAMUNDO_H
#define P1HOLAMUNDO_H

#include "../../mod/Programa.h"

class P1HolaMundo : public Programa {
public:
    ResultadoPrograma ejecutar() {
        return ResultadoPrograma(
            "P1 - Hola Mundo",
            "Programa basico que muestra un mensaje en pantalla.",
            "No requiere datos de entrada.",
            "Hola Mundo"
        );
    }
};

#endif
