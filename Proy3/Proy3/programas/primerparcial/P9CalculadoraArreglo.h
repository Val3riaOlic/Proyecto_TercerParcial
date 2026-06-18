#ifndef P9CALCULADORAARREGLO_H
#define P9CALCULADORAARREGLO_H

#include "../../mod/Programa.h"
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class P9CalculadoraArreglo : public Programa {
private:
    double numeros[5];

public:
    P9CalculadoraArreglo(vector<double> valores) {
        while (valores.size() < 5) valores.push_back(0);
        for (int i = 0; i < 5; i++) numeros[i] = valores[i];
    }

    double suma() {
        double total = 0;
        for (int i = 0; i < 5; i++) total += numeros[i];
        return total;
    }

    double promedio() {
        return suma() / 5.0;
    }

    double maximo() {
        double max = numeros[0];
        for (int i = 1; i < 5; i++) {
            if (numeros[i] > max) max = numeros[i];
        }
        return max;
    }

    double minimo() {
        double min = numeros[0];
        for (int i = 1; i < 5; i++) {
            if (numeros[i] < min) min = numeros[i];
        }
        return min;
    }

    double mediana() {
        double temp[5];
        for (int i = 0; i < 5; i++) temp[i] = numeros[i];
        sort(temp, temp + 5);
        return temp[2];
    }

    ResultadoPrograma ejecutar() {
        stringstream entrada;
        for (int i = 0; i < 5; i++) {
            entrada << "Numero " << (i + 1) << ": " << numeros[i];
            if (i < 4) entrada << "\n";
        }

        stringstream salida;
        salida << "Suma: " << suma() << "\n";
        salida << "Promedio: " << promedio() << "\n";
        salida << "Maximo: " << maximo() << "\n";
        salida << "Minimo: " << minimo() << "\n";
        salida << "Mediana: " << mediana();

        return ResultadoPrograma(
            "P9 - Calculadora con Arreglo",
            "Calculadora que usa arreglo de 5 elementos.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
