#ifndef P10PROMEDIOCONARREGLO_H
#define P10PROMEDIOCONARREGLO_H

#include "../../mod/Programa.h"
#include <sstream>
#include <vector>
using namespace std;

class P10PromedioConArreglo : public Programa {
private:
    float numeros[5];

public:
    P10PromedioConArreglo(vector<float> valores) {
        while (valores.size() < 5) valores.push_back(0);
        for (int i = 0; i < 5; i++) numeros[i] = valores[i];
    }

    ResultadoPrograma ejecutar() {
        float *p = numeros;
        float prom = 0, maximo = *p, minimo = *p, suma = 0;

        for (int i = 0; i < 5; i++) {
            suma += *(p + i);

            if (*(p + i) > maximo) maximo = *(p + i);
            if (*(p + i) < minimo) minimo = *(p + i);
        }

        prom = suma / 5;

        stringstream entrada;
        for (int i = 0; i < 5; i++) {
            entrada << "Numero " << (i + 1) << ": " << numeros[i];
            if (i < 4) entrada << "\n";
        }

        stringstream salida;
        salida << "Numero maximo: " << maximo << "\n";
        salida << "Numero minimo: " << minimo << "\n";
        salida << "Suma total: " << suma << "\n";
        salida << "Promedio: " << prom;

        return ResultadoPrograma(
            "P10 - Promedio con Arreglo",
            "Calcula maximo, minimo, suma y promedio usando arreglo y puntero.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
