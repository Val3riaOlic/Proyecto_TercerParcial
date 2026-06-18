#ifndef P5HERENCIA_H
#define P5HERENCIA_H

#include "../../mod/Programa.h"
#include <sstream>
#include <cmath>
using namespace std;

class CalculadoraP5 {
protected:
    int a;
    int b;

public:
    void setValores(int x, int y) {
        a = x;
        b = y;
    }

    virtual int multiplicar() {
        return a * b;
    }

    virtual int dividir() {
        if (b == 0) return 0;
        return a / b;
    }

    virtual double potencia() {
        double res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
        }
        return res;
    }

    virtual ~CalculadoraP5() {}
};

class CalculadoraNuevaP5 : public CalculadoraP5 {
public:
    int multiplicar() {
        int res = 0;
        int signo = 1;

        int x = a;
        int y = b;

        if (x < 0) {
            x = -x;
            signo *= -1;
        }

        if (y < 0) {
            y = -y;
            signo *= -1;
        }

        for (int i = 0; i < y; i++) {
            res += x;
        }

        return res * signo;
    }

    int dividir() {
        if (b == 0) {
            return 0;
        }

        int signo = 1;
        int x = a;
        int y = b;

        if (x < 0) {
            x = -x;
            signo *= -1;
        }

        if (y < 0) {
            y = -y;
            signo *= -1;
        }

        int cont = 0;
        while (x >= y) {
            x -= y;
            cont++;
        }

        return cont * signo;
    }

    double potencia() {
        int base = a;
        int exp = b;
        int signo = 1;

        if (base < 0) {
            base = -base;
            if (exp % 2 != 0) {
                signo = -1;
            }
        }

        int exponente = exp;
        if (exp < 0) {
            exponente = -exp;
        }

        double res = 1.0;

        for (int i = 0; i < exponente; i++) {
            double temp = 0.0;
            for (int j = 0; j < base; j++) {
                temp += res;
            }
            res = temp;
        }

        if (exp < 0) {
            res = 1.0 / res;
        }

        return res * signo;
    }
};

class P5Herencia : public Programa {
private:
    int x;
    int y;

public:
    P5Herencia(int x, int y) {
        this->x = x;
        this->y = y;
    }

    ResultadoPrograma ejecutar() {
        CalculadoraNuevaP5 calc;
        calc.setValores(x, y);

        stringstream entrada;
        entrada << "Numero 1: " << x << "\n";
        entrada << "Numero 2: " << y;

        stringstream salida;
        salida << "Resultados usando CalculadoraNueva:\n";
        salida << "Multiplicacion: " << calc.multiplicar() << "\n";
        if (y == 0) salida << "Division: no se puede dividir entre cero\n";
        else salida << "Division: " << calc.dividir() << "\n";
        salida << "Potencia: " << calc.potencia();

        return ResultadoPrograma(
            "P5 - Herencia",
            "CalculadoraNueva hereda de Calculadora y redefine operaciones.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
