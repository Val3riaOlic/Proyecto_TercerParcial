#ifndef PILAARREGLODB_H
#define PILAARREGLODB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class PilaArregloDB : public Programa {
private:
    vector<int> datos;
    int capacidad;

public:
    PilaArregloDB(vector<int> datos, int capacidad = 100) {
        this->datos = datos;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> pila;

        for (size_t i = 0; i < datos.size() && (int)pila.size() < capacidad; i++) {
            pila.push_back(datos[i]);
        }

        stringstream entrada;
        entrada << "Datos ingresados: " << UtilSP::vectorEnterosToString(datos) << "\n";
        entrada << "Capacidad de la pila: " << capacidad;

        stringstream salida;
        salida << "Contenido de la pila de tope a base:\n";
        if (pila.empty()) {
            salida << "La pila esta vacia.";
        } else {
            for (int i = (int)pila.size() - 1; i >= 0; i--) {
                salida << pila[i] << "\n";
            }
            salida << "\nTamanio actual: " << pila.size();
        }

        return ResultadoPrograma(
            "Pila con Arreglo - Dato Basico",
            "Estructura tipo pila implementada con arreglo. Inserta datos enteros y muestra el contenido del tope a la base.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
