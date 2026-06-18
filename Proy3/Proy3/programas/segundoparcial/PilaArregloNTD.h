#ifndef PILAARREGLONTD_H
#define PILAARREGLONTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class PilaArregloNTD : public Programa {
private:
    vector<PersonaSP> personas;
    int capacidad;

public:
    PilaArregloNTD(vector<PersonaSP> personas, int capacidad = 100) {
        this->personas = personas;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> pila;

        for (size_t i = 0; i < personas.size() && (int)pila.size() < capacidad; i++) {
            pila.push_back(personas[i]);
        }

        stringstream entrada;
        entrada << "Personas ingresadas:\n";
        for (size_t i = 0; i < personas.size(); i++) {
            entrada << personas[i].toString() << "\n";
        }
        entrada << "Capacidad de la pila: " << capacidad;

        stringstream salida;
        salida << "Contenido de la pila de tope a base:\n";
        if (pila.empty()) {
            salida << "La pila esta vacia.";
        } else {
            for (int i = (int)pila.size() - 1; i >= 0; i--) {
                salida << pila[i].toString() << "\n";
            }
            salida << "\nTamanio actual: " << pila.size();
        }

        return ResultadoPrograma(
            "Pila con Arreglo - Nuevo Tipo de Dato",
            "Estructura tipo pila implementada con arreglo usando objetos PersonaSP.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
