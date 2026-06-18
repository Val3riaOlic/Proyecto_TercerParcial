#ifndef QUICKDB_H
#define QUICKDB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class QuickDB : public Programa {
private:
    vector<int> datos;

    int particion(vector<int>& arr, int bajo, int alto) {
        int pivote = arr[alto];
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (arr[j] < pivote) {
                i++;
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        int aux = arr[i + 1];
        arr[i + 1] = arr[alto];
        arr[alto] = aux;

        return i + 1;
    }

    void quickSort(vector<int>& arr, int bajo, int alto) {
        if (bajo < alto) {
            int pi = particion(arr, bajo, alto);
            quickSort(arr, bajo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }

public:
    QuickDB(vector<int> datos) {
        this->datos = datos;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> ordenado = datos;

        if (!ordenado.empty()) {
            quickSort(ordenado, 0, (int)ordenado.size() - 1);
        }

        return ResultadoPrograma(
            "Ordenamiento Quick Sort - Dato Basico",
            "Ordena un arreglo de numeros enteros mediante el metodo Quick Sort.",
            "Arreglo original: " + UtilSP::vectorEnterosToString(datos),
            "Arreglo ordenado: " + UtilSP::vectorEnterosToString(ordenado)
        );
    }
};

#endif
