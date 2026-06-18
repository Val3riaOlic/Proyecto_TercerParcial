#ifndef BURBUJADB_H
#define BURBUJADB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class BurbujaDB : public Programa {
private:
    vector<int> datos;

public:
    BurbujaDB(vector<int> datos) {
        this->datos = datos;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> ordenado = datos;

        for (size_t i = 0; i < ordenado.size(); i++) {
            for (size_t j = 0; j + 1 < ordenado.size() - i; j++) {
                if (ordenado[j] > ordenado[j + 1]) {
                    int aux = ordenado[j];
                    ordenado[j] = ordenado[j + 1];
                    ordenado[j + 1] = aux;
                }
            }
        }

        return ResultadoPrograma(
            "Ordenamiento Burbuja - Dato Basico",
            "Ordena un arreglo de numeros enteros mediante el metodo burbuja.",
            "Arreglo original: " + UtilSP::vectorEnterosToString(datos),
            "Arreglo ordenado: " + UtilSP::vectorEnterosToString(ordenado)
        );
    }
};

#endif
