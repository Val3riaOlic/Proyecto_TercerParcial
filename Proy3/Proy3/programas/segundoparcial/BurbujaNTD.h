#ifndef BURBUJANTD_H
#define BURBUJANTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class BurbujaNTD : public Programa {
private:
    vector<PersonaSP> personas;

    string personasToString(const vector<PersonaSP>& datos) {
        stringstream ss;
        for (size_t i = 0; i < datos.size(); i++) {
            ss << datos[i].toString() << "\n";
        }
        return ss.str();
    }

public:
    BurbujaNTD(vector<PersonaSP> personas) {
        this->personas = personas;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> ordenado = personas;

        for (size_t i = 0; i < ordenado.size(); i++) {
            for (size_t j = 0; j + 1 < ordenado.size() - i; j++) {
                if (ordenado[j].getEdad() > ordenado[j + 1].getEdad()) {
                    PersonaSP aux = ordenado[j];
                    ordenado[j] = ordenado[j + 1];
                    ordenado[j + 1] = aux;
                }
            }
        }

        return ResultadoPrograma(
            "Ordenamiento Burbuja - Nuevo Tipo de Dato",
            "Ordena personas por edad mediante el metodo burbuja.",
            "Personas originales:\n" + personasToString(personas),
            "Personas ordenadas por edad:\n" + personasToString(ordenado)
        );
    }
};

#endif
