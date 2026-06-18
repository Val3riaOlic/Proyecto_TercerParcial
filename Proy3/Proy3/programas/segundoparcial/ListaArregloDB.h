#ifndef LISTAARREGLODB_H
#define LISTAARREGLODB_H

#include "../../mod/Programa.h"
#include "UtilSP.h"
#include <vector>
#include <sstream>

using namespace std;

class ListaArregloDB : public Programa {
private:
    vector<int> datos;
    int capacidad;

public:
    ListaArregloDB(vector<int> datos, int capacidad = 100) {
        this->datos = datos;
        this->capacidad = capacidad;
    }

    ResultadoPrograma ejecutar() override {
        vector<int> lista;

        for (size_t i = 0; i < datos.size() && (int)lista.size() < capacidad; i++) {
            lista.push_back(datos[i]);
        }

        stringstream entrada;
        entrada << "Datos ingresados: " << UtilSP::vectorEnterosToString(datos) << "\n";
        entrada << "Capacidad de la lista: " << capacidad;

        stringstream salida;
        salida << "Contenido de la lista:\n";
        if (lista.empty()) {
            salida << "La lista esta vacia.";
        } else {
            salida << UtilSP::vectorEnterosConIndice(lista);
            salida << "\nTamanio actual: " << lista.size();
        }

        return ResultadoPrograma(
            "Lista con Arreglo - Dato Basico",
            "Estructura tipo lista implementada con arreglo para almacenar numeros enteros.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
