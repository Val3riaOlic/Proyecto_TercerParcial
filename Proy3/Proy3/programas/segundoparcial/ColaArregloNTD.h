#ifndef COLAARREGLONTD_H
#define COLAARREGLONTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class ColaArregloNTD : public Programa {
private:
    vector<PersonaSP> personas;
    int capacidad;

public:
    ColaArregloNTD(vector<PersonaSP> personas, int capacidad = 100) {
        this->personas = personas;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> cola;

        for (size_t i = 0; i < personas.size() && (int)cola.size() < capacidad; i++) {
            cola.push_back(personas[i]);
        }

        stringstream entrada;
        entrada << "Personas ingresadas:\n";
        for (size_t i = 0; i < personas.size(); i++) {
            entrada << personas[i].toString() << "\n";
        }
        entrada << "Capacidad de la cola: " << capacidad;

        stringstream salida;
        salida << "Contenido de la cola de frente a final:\n";
        if (cola.empty()) {
            salida << "La cola esta vacia.";
        } else {
            for (size_t i = 0; i < cola.size(); i++) {
                salida << cola[i].toString() << "\n";
            }
            salida << "\nTamanio actual: " << cola.size();
        }

        return ResultadoPrograma(
            "Cola con Arreglo - Nuevo Tipo de Dato",
            "Estructura tipo cola implementada con arreglo usando objetos PersonaSP.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
