#ifndef P14CALCULADORARECURSIVA_H
#define P14CALCULADORARECURSIVA_H

#include "../../mod/Programa.h"
#include <sstream>
#include <cstdlib>
using namespace std;

class CalculadoraRecP14 {
protected:
    int a;
    int b;

public:
    void setValores(int x, int y) {
        a = x;
        b = y;
    }

    virtual int multiplicar() { return a * b; }

    virtual int dividir() {
        if (b == 0) return 0;
        return a / b;
    }

    virtual int potencia() {
        int res = 1;
        for (int i = 0; i < b; i++) res *= a;
        return res;
    }

    virtual ~CalculadoraRecP14() {}
};

class CalculadoraNuevaRecP14 : public CalculadoraRecP14 {
private:
    int multRec(int x, int y) {
        if (y == 0) return 0;
        if (y > 0) return x + multRec(x, y - 1);
        return -multRec(x, -y);
    }

    int divRec(int x, int y) {
        if (y == 0) return 0;
        bool negativo = (x < 0) != (y < 0);
        int ax = abs(x);
        int ay = abs(y);
        int res = 0;

        while (ax >= ay) {
            ax -= ay;
            res++;
        }

        return negativo ? -res : res;
    }

    int potRec(int x, int y) {
        if (y < 0) return 0;
        if (y == 0) return 1;
        return x * potRec(x, y - 1);
    }

public:
    int multiplicar() {
        return multRec(a, b);
    }

    int dividir() {
        if (b == 0) return 0;
        return divRec(a, b);
    }

    int potencia() {
        return potRec(a, b);
    }
};

class P14CalculadoraRecursiva : public Programa {
private:
    int x;
    int y;

public:
    P14CalculadoraRecursiva(int x, int y) {
        this->x = x;
        this->y = y;
    }

    ResultadoPrograma ejecutar() {
        CalculadoraNuevaRecP14 c;
        c.setValores(x, y);

        stringstream entrada;
        entrada << "Base / numero 1: " << x << "\n";
        entrada << "Numero 2 / exponente: " << y;

        stringstream salida;
        salida << "Multiplicacion (sumas recursivas): " << c.multiplicar() << "\n";
        if (y == 0) salida << "Division: no se puede dividir entre 0\n";
        else salida << "Division (restas recursivas): " << c.dividir() << "\n";
        if (y < 0) salida << "Potencia: no se soportan exponentes negativos";
        else salida << "Potencia (multiplicaciones recursivas): " << c.potencia();

        return ResultadoPrograma(
            "P14 - Calculadora Recursiva",
            "Calculadora que usa recursividad para multiplicacion, division y potencia.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
