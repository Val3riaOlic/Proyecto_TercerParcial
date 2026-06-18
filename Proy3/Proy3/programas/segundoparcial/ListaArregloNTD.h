#ifndef LISTAARREGLONTD_H
#define LISTAARREGLONTD_H

#include "../../mod/Programa.h"
#include "PersonaSP.h"
#include <vector>
#include <sstream>

using namespace std;

class ListaArregloNTD : public Programa {
private:
    vector<PersonaSP> personas;
    int capacidad;

public:
    ListaArregloNTD(vector<PersonaSP> personas, int capacidad = 100) {
        this->personas = personas;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<PersonaSP> lista;

        for (size_t i = 0; i < personas.size() && (int)lista.size() < capacidad; i++) {
            lista.push_back(personas[i]);
        }

        stringstream entrada;
        entrada << "Personas ingresadas:\n";
        for (size_t i = 0; i < personas.size(); i++) {
            entrada << personas[i].toString() << "\n";
        }
        entrada << "Capacidad de la lista: " << capacidad;

        stringstream salida;
        salida << "Contenido de la lista:\n";
        if (lista.empty()) {
            salida << "La lista esta vacia.";
        } else {
            for (size_t i = 0; i < lista.size(); i++) {
                salida << "Posicion " << i << ": " << lista[i].toString() << "\n";
            }
            salida << "\nTamanio actual: " << lista.size();
        }

        return ResultadoPrograma(
            "Lista con Arreglo - Nuevo Tipo de Dato",
            "Estructura tipo lista implementada con arreglo usando objetos PersonaSP.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
