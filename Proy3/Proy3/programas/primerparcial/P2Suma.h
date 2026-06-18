#ifndef P2SUMA_H
#define P2SUMA_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class P2Suma : public Programa {
private:
    float a;
    float b;

public:
    P2Suma(float a, float b) {
        this->a = a;
        this->b = b;
    }

    float operacion(float x, float y) {
        return x + y;
    }

    ResultadoPrograma ejecutar() {
        float r = operacion(a, b);

        stringstream entrada;
        entrada << "Parametro 1: " << a << "\n";
        entrada << "Parametro 2: " << b;

        stringstream salida;
        salida << "El resultado es: " << r;

        return ResultadoPrograma(
            "P2 - Suma",
            "Suma dos numeros usando una clase.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
