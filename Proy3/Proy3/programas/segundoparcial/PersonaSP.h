#ifndef PERSONASP_H
#define PERSONASP_H

#include <string>
#include <sstream>

using namespace std;

class PersonaSP {
private:
    string nombre;
    int edad;

public:
    PersonaSP() {
        nombre = "";
        edad = 0;
    }

    PersonaSP(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    string toString() const {
        stringstream ss;
        ss << "Nombre: " << nombre << " | Edad: " << edad;
        return ss.str();
    }
};

#endif
