#ifndef MERGEDB_H
#define MERGEDB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class MergeDB : public Programa {
private:
    vector<int> datos;

    void merge(vector<int>& arr, int izquierda, int medio, int derecha) {
        vector<int> temp;
        int i = izquierda;
        int j = medio + 1;

        while (i <= medio && j <= derecha) {
            if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }

        while (i <= medio) temp.push_back(arr[i++]);
        while (j <= derecha) temp.push_back(arr[j++]);

        for (size_t k = 0; k < temp.size(); k++) {
            arr[izquierda + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& arr, int izquierda, int derecha) {
        if (izquierda < derecha) {
            int medio = (izquierda + derecha) / 2;
            mergeSort(arr, izquierda, medio);
            mergeSort(arr, medio + 1, derecha);
            merge(arr, izquierda, medio, derecha);
        }
    }

public:
    MergeDB(vector<int> datos) {
        this->datos = datos;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> ordenado = datos;

        if (!ordenado.empty()) {
            mergeSort(ordenado, 0, (int)ordenado.size() - 1);
        }

        return ResultadoPrograma(
            "Ordenamiento Merge Sort - Dato Basico",
            "Ordena un arreglo de numeros enteros mediante el metodo Merge Sort.",
            "Arreglo original: " + UtilSP::vectorEnterosToString(datos),
            "Arreglo ordenado: " + UtilSP::vectorEnterosToString(ordenado)
        );
    }
};

#endif
