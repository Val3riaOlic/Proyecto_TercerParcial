#ifndef DATOSAUTOPERSONA_H
#define DATOSAUTOPERSONA_H

#include <string>
using namespace std;

struct DatosAutoPersona {
    float precio;
    int anio;
    string marca;

    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

    DatosAutoPersona() {
        precio = 0;
        anio = 0;
        marca = "";
        nombre = "";
        ap = "";
        am = "";
        genero = "";
        edad = 0;
    }
};

#endif
