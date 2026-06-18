#ifndef P14RECURSIVIDAD_H
#define P14RECURSIVIDAD_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class RecursividadP14 {
public:
    int factorial(int num) {
        if (num == 0 || num == 1) {
            return 1;
        } else {
            return num * factorial(num - 1);
        }
    }

    int fibonacci(int num) {
        if (num == 0) return 0;
        if (num == 1) return 1;
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
};

class P14Recursividad : public Programa {
private:
    int num;

public:
    P14Recursividad(int num) {
        this->num = num;
    }

    ResultadoPrograma ejecutar() {
        RecursividadP14 obj;

        stringstream entrada;
        entrada << "Numero: " << num;

        stringstream salida;

        if (num < 0) {
            salida << "Error: el numero debe ser mayor o igual a cero.";
        } else {
            salida << "Factorial: " << obj.factorial(num) << "\n";
            salida << "Fibonacci: ";
            for (int i = 0; i <= num; i++) {
                salida << obj.fibonacci(i);
                if (i < num) salida << " ";
            }
        }

        return ResultadoPrograma(
            "P14 - Recursividad",
            "Calcula factorial y serie Fibonacci usando recursividad.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
