#ifndef P3CALCULADORABASICA_H
#define P3CALCULADORABASICA_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class P3CalculadoraBasica : public Programa {
private:
    int opcion;
    float a;
    float b;

public:
    P3CalculadoraBasica(int opcion, float a, float b) {
        this->opcion = opcion;
        this->a = a;
        this->b = b;
    }

    float suma(float x, float y) { return x + y; }
    float resta(float x, float y) { return x - y; }
    float multiplicacion(float x, float y) { return x * y; }
    float division(float x, float y) { return x / y; }

    ResultadoPrograma ejecutar() {
        string operacion;
        stringstream salida;

        if (opcion == 1) {
            operacion = "Suma";
            salida << "Resultado: " << suma(a, b);
        } else if (opcion == 2) {
            operacion = "Resta";
            salida << "Resultado: " << resta(a, b);
        } else if (opcion == 3) {
            operacion = "Multiplicacion";
            salida << "Resultado: " << multiplicacion(a, b);
        } else if (opcion == 4) {
            operacion = "Division";
            if (b == 0) {
                salida << "Error: no se puede dividir entre cero.";
            } else {
                salida << "Resultado: " << division(a, b);
            }
        } else {
            operacion = "Opcion no valida";
            salida << "No se selecciono una operacion valida.";
        }

        stringstream entrada;
        entrada << "Operacion: " << operacion << "\n";
        entrada << "Numero 1: " << a << "\n";
        entrada << "Numero 2: " << b;

        return ResultadoPrograma(
            "P3 - Calculadora Basica",
            "Calculadora con suma, resta, multiplicacion y division.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
