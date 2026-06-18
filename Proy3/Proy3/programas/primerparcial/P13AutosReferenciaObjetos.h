#ifndef P13AUTOSREFERENCIAOBJETOS_H
#define P13AUTOSREFERENCIAOBJETOS_H

#include "../../mod/Programa.h"
#include "DatosAutoPersona.h"
#include <sstream>
#include <vector>
using namespace std;

class AutoP13 {
private:
    float precio;
    int anio;
    string marca;

    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

public:
    void setDatos(float p, int a, string m, string n, string apP, string apM, string g, int e) {
        precio = p;
        anio = a;
        marca = m;

        nombre = n;
        ap = apP;
        am = apM;
        genero = g;
        edad = e;
    }

    string mostrarDatos() const {
        stringstream ss;
        ss << "DATOS DEL PROPIETARIO\n";
        ss << "Nombre: " << nombre << " " << ap << " " << am << "\n";
        ss << "Genero: " << genero << "\n";
        ss << "Edad: " << edad << "\n\n";
        ss << "DATOS DEL AUTO\n";
        ss << "Marca: " << marca << "\n";
        ss << "Precio: " << precio << "\n";
        ss << "Anio: " << anio;
        return ss.str();
    }
};

class P13AutosReferenciaObjetos : public Programa {
private:
    vector<DatosAutoPersona> datos;

public:
    P13AutosReferenciaObjetos(vector<DatosAutoPersona> datos) {
        this->datos = datos;
        while (this->datos.size() < 3) this->datos.push_back(DatosAutoPersona());
        if (this->datos.size() > 3) this->datos.resize(3);
    }

    ResultadoPrograma ejecutar() {
        AutoP13 lista[3];
        AutoP13 *p = lista;

        for (int i = 0; i < 3; i++) {
            (p + i)->setDatos(
                datos[i].precio,
                datos[i].anio,
                datos[i].marca,
                datos[i].nombre,
                datos[i].ap,
                datos[i].am,
                datos[i].genero,
                datos[i].edad
            );
        }

        stringstream entrada;
        for (int i = 0; i < 3; i++) {
            entrada << "Persona " << (i + 1) << ": "
                    << datos[i].nombre << " " << datos[i].ap << " " << datos[i].am
                    << ", Auto: " << datos[i].marca
                    << ", Precio: " << datos[i].precio
                    << ", Anio: " << datos[i].anio;
            if (i < 2) entrada << "\n";
        }

        stringstream salida;
        salida << "----- LISTA DE PERSONAS Y AUTOS CON PUNTERO -----\n\n";
        for (int i = 0; i < 3; i++) {
            salida << (p + i)->mostrarDatos();
            if (i < 2) salida << "\n\n";
        }

        return ResultadoPrograma(
            "P13 - Autos Referencia a Objetos",
            "Usa un puntero al arreglo de objetos para manejar personas y autos.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
