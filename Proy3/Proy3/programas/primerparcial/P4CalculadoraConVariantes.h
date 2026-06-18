#ifndef P4CALCULADORACONVARIANTES_H
#define P4CALCULADORACONVARIANTES_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class P4CalculadoraConVariantes : public Programa {
private:
    int operacion;
    int parametros;
    float a;
    float b;
    float c;

public:
    P4CalculadoraConVariantes(int operacion, int parametros, float a, float b, float c = 0) {
        this->operacion = operacion;
        this->parametros = parametros;
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float suma2(float x, float y) { return x + y; }
    float resta2(float x, float y) { return x - y; }
    float multiplicacion2(float x, float y) { return x * y; }
    float division2(float x, float y) { return x / y; }

    float suma3(float x, float y, float z) { return x + y + z; }
    float resta3(float x, float y, float z) { return x - y - z; }
    float multiplicacion3(float x, float y, float z) { return x * y * z; }
    float division3(float x, float y, float z) { return (x / y) / z; }

    ResultadoPrograma ejecutar() {
        string nombreOperacion;
        stringstream salida;

        if (operacion == 1) nombreOperacion = "Suma";
        else if (operacion == 2) nombreOperacion = "Resta";
        else if (operacion == 3) nombreOperacion = "Multiplicacion";
        else if (operacion == 4) nombreOperacion = "Division";
        else nombreOperacion = "Opcion no valida";

        if (parametros == 2) {
            if (operacion == 1) salida << "Resultado: " << suma2(a, b);
            else if (operacion == 2) salida << "Resultado: " << resta2(a, b);
            else if (operacion == 3) salida << "Resultado: " << multiplicacion2(a, b);
            else if (operacion == 4) {
                if (b == 0) salida << "Error: no se puede dividir entre cero.";
                else salida << "Resultado: " << division2(a, b);
            } else salida << "Opcion no valida.";
        } else if (parametros == 3) {
            if (operacion == 1) salida << "Resultado: " << suma3(a, b, c);
            else if (operacion == 2) salida << "Resultado: " << resta3(a, b, c);
            else if (operacion == 3) salida << "Resultado: " << multiplicacion3(a, b, c);
            else if (operacion == 4) {
                if (b == 0 || c == 0) salida << "Error: no se puede dividir entre cero.";
                else salida << "Resultado: " << division3(a, b, c);
            } else salida << "Opcion no valida.";
        } else {
            salida << "Cantidad de parametros no valida. Usa 2 o 3 parametros.";
        }

        stringstream entrada;
        entrada << "Operacion: " << nombreOperacion << "\n";
        entrada << "Parametros seleccionados: " << parametros << "\n";
        entrada << "Numero 1: " << a << "\n";
        entrada << "Numero 2: " << b;
        if (parametros == 3) entrada << "\nNumero 3: " << c;

        return ResultadoPrograma(
            "P4 - Calculadora con Variantes",
            "Calculadora con metodos de 2 y 3 parametros.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
