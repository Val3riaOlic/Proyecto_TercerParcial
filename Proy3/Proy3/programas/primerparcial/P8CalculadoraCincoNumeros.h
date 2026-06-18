#ifndef P8CALCULADORACINCONUMEROS_H
#define P8CALCULADORACINCONUMEROS_H

#include "../../mod/Programa.h"
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class P8CalculadoraCincoNumeros : public Programa {
private:
    vector<double> numeros;

public:
    P8CalculadoraCincoNumeros(vector<double> numeros) {
        this->numeros = numeros;
        while (this->numeros.size() < 5) this->numeros.push_back(0);
        if (this->numeros.size() > 5) this->numeros.resize(5);
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
        for (int i = 1; i < 5; i++) if (numeros[i] > max) max = numeros[i];
        return max;
    }

    double minimo() {
        double min = numeros[0];
        for (int i = 1; i < 5; i++) if (numeros[i] < min) min = numeros[i];
        return min;
    }

    double mediana() {
        vector<double> temp = numeros;
        sort(temp.begin(), temp.end());
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
            "P8 - Calculadora 5 Numeros",
            "Calcula suma, promedio, maximo, minimo y mediana de 5 numeros.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
