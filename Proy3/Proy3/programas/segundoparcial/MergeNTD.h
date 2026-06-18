#ifndef MERGENTD_H
#define MERGENTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class MergeNTD : public Programa {
private:
    vector<PersonaSP> personas;

    string personasToString(const vector<PersonaSP>& datos) {
        stringstream ss;
        for (size_t i = 0; i < datos.size(); i++) {
            ss << datos[i].toString() << "\n";
        }
        return ss.str();
    }

    void merge(vector<PersonaSP>& arr, int izquierda, int medio, int derecha) {
        vector<PersonaSP> temp;
        int i = izquierda;
        int j = medio + 1;

        while (i <= medio && j <= derecha) {
            if (arr[i].getEdad() <= arr[j].getEdad()) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }

        while (i <= medio) temp.push_back(arr[i++]);
        while (j <= derecha) temp.push_back(arr[j++]);

        for (size_t k = 0; k < temp.size(); k++) {
            arr[izquierda + k] = temp[k];
        }
    }

    void mergeSort(vector<PersonaSP>& arr, int izquierda, int derecha) {
        if (izquierda < derecha) {
            int medio = (izquierda + derecha) / 2;
            mergeSort(arr, izquierda, medio);
            mergeSort(arr, medio + 1, derecha);
            merge(arr, izquierda, medio, derecha);
        }
    }

public:
    MergeNTD(vector<PersonaSP> personas) {
        this->personas = personas;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> ordenado = personas;

        if (!ordenado.empty()) {
            mergeSort(ordenado, 0, (int)ordenado.size() - 1);
        }

        return ResultadoPrograma(
            "Ordenamiento Merge Sort - Nuevo Tipo de Dato",
            "Ordena personas por edad mediante el metodo Merge Sort.",
            "Personas originales:\n" + personasToString(personas),
            "Personas ordenadas por edad:\n" + personasToString(ordenado)
        );
    }
};

#endif
