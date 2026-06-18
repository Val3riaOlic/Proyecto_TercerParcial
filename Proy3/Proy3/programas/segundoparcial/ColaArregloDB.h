#ifndef COLAARREGLODB_H
#define COLAARREGLODB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class ColaArregloDB : public Programa {
private:
    vector<int> datos;
    int capacidad;

public:
    ColaArregloDB(vector<int> datos, int capacidad = 100) {
        this->datos = datos;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> cola;

        for (size_t i = 0; i < datos.size() && (int)cola.size() < capacidad; i++) {
            cola.push_back(datos[i]);
        }

        stringstream entrada;
        entrada << "Datos ingresados: " << UtilSP::vectorEnterosToString(datos) << "\n";
        entrada << "Capacidad de la cola: " << capacidad;

        stringstream salida;
        salida << "Contenido de la cola de frente a final:\n";
        if (cola.empty()) {
            salida << "La cola esta vacia.";
        } else {
            for (size_t i = 0; i < cola.size(); i++) {
                salida << cola[i] << "\n";
            }
            salida << "\nTamanio actual: " << cola.size();
        }

        return ResultadoPrograma(
            "Cola con Arreglo - Dato Basico",
            "Estructura tipo cola implementada con arreglo. Inserta enteros y los muestra de frente a final.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
