#ifndef QUICKNTD_H
#define QUICKNTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class QuickNTD : public Programa {
private:
    vector<PersonaSP> personas;

    string personasToString(const vector<PersonaSP>& datos) {
        stringstream ss;
        for (size_t i = 0; i < datos.size(); i++) {
            ss << datos[i].toString() << "\n";
        }
        return ss.str();
    }

    int particion(vector<PersonaSP>& arr, int bajo, int alto) {
        int pivote = arr[alto].getEdad();
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (arr[j].getEdad() < pivote) {
                i++;
                PersonaSP aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        PersonaSP aux = arr[i + 1];
        arr[i + 1] = arr[alto];
        arr[alto] = aux;

        return i + 1;
    }

    void quickSort(vector<PersonaSP>& arr, int bajo, int alto) {
        if (bajo < alto) {
            int pi = particion(arr, bajo, alto);
            quickSort(arr, bajo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }

public:
    QuickNTD(vector<PersonaSP> personas) {
        this->personas = personas;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> ordenado = personas;

        if (!ordenado.empty()) {
            quickSort(ordenado, 0, (int)ordenado.size() - 1);
        }

        return ResultadoPrograma(
            "Ordenamiento Quick Sort - Nuevo Tipo de Dato",
            "Ordena personas por edad mediante el metodo Quick Sort.",
            "Personas originales:\n" + personasToString(personas),
            "Personas ordenadas por edad:\n" + personasToString(ordenado)
        );
    }
};

#endif
