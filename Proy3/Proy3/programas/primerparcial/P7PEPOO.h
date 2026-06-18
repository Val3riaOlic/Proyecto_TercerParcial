#ifndef P7PEPOO_H
#define P7PEPOO_H

#include "../../mod/Programa.h"
#include <sstream>
#include <string>
using namespace std;

struct AutoPE_P7 {
    float precio;
    int anio;
};

class AutoPOO_P7 {
private:
    float precio;
    int anio;

public:
    AutoPOO_P7(float p, int a) {
        precio = p;
        anio = a;
    }

    string mostrar() {
        stringstream ss;
        ss << "Auto POO - Precio: $" << precio << ", Anio: " << anio;
        return ss.str();
    }
};

class PersonaP7 {
private:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

public:
    PersonaP7(string n, string p, string m, string g, int e) {
        nombre = n;
        ap = p;
        am = m;
        genero = g;
        edad = e;
    }

    string mostrar() {
        stringstream ss;
        ss << "Persona - Nombre: " << nombre << " " << ap << " " << am << "\n";
        ss << "Genero: " << genero << ", Edad: " << edad;
        return ss.str();
    }
};

class P7PEPOO : public Programa {
private:
    float precioPE;
    int anioPE;

    float precioPOO;
    int anioPOO;
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

public:
    P7PEPOO(float precioPE, int anioPE, float precioPOO, int anioPOO,
            string nombre, string ap, string am, string genero, int edad) {
        this->precioPE = precioPE;
        this->anioPE = anioPE;
        this->precioPOO = precioPOO;
        this->anioPOO = anioPOO;
        this->nombre = nombre;
        this->ap = ap;
        this->am = am;
        this->genero = genero;
        this->edad = edad;
    }

    ResultadoPrograma ejecutar() {
        AutoPE_P7 autoPE;
        autoPE.precio = precioPE;
        autoPE.anio = anioPE;

        AutoPOO_P7 autoPOO(precioPOO, anioPOO);
        PersonaP7 persona(nombre, ap, am, genero, edad);

        stringstream entrada;
        entrada << "Auto PE - Precio: " << precioPE << ", Anio: " << anioPE << "\n";
        entrada << "Auto POO - Precio: " << precioPOO << ", Anio: " << anioPOO << "\n";
        entrada << "Persona: " << nombre << " " << ap << " " << am << "\n";
        entrada << "Genero: " << genero << "\n";
        entrada << "Edad: " << edad;

        stringstream salida;
        salida << "=== Datos desde PE ===\n";
        salida << "Auto PE - Precio: $" << autoPE.precio << ", Anio: " << autoPE.anio << "\n\n";
        salida << "=== Datos desde POO ===\n";
        salida << autoPOO.mostrar() << "\n";
        salida << persona.mostrar();

        return ResultadoPrograma(
            "P7 - PE y POO",
            "Compara estructura estilo PE con clases de POO.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
