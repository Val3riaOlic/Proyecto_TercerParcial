#ifndef P12AUTOSARREGLOOBJETOS_H
#define P12AUTOSARREGLOOBJETOS_H

#include "../../mod/Programa.h"
#include "DatosAutoPersona.h"
#include <sstream>
#include <vector>
using namespace std;

class AutoP12 {
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

class P12AutosArregloObjetos : public Programa {
private:
    vector<DatosAutoPersona> datos;

public:
    P12AutosArregloObjetos(vector<DatosAutoPersona> datos) {
        this->datos = datos;
        while (this->datos.size() < 3) this->datos.push_back(DatosAutoPersona());
        if (this->datos.size() > 3) this->datos.resize(3);
    }

    ResultadoPrograma ejecutar() {
        AutoP12 lista[3];

        for (int i = 0; i < 3; i++) {
            lista[i].setDatos(
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
        salida << "----- LISTA DE PERSONAS Y AUTOS -----\n\n";
        for (int i = 0; i < 3; i++) {
            salida << lista[i].mostrarDatos();
            if (i < 2) salida << "\n\n";
        }

        return ResultadoPrograma(
            "P12 - Autos Arreglo de Objetos",
            "Captura 3 personas con sus autos usando arreglo de objetos.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
