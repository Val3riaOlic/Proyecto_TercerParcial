#ifndef P6SOBREESCRITURA_H
#define P6SOBREESCRITURA_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class CalculadoraP6 {
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

    virtual int potencia() {
        int res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
        }
        return res;
    }

    virtual ~CalculadoraP6() {}
};

class CalculadoraNuevaP6 : public CalculadoraP6 {
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

    int potencia() {
        if (b < 0) {
            return 0;
        }

        int base = a;
        int exp = b;
        int signo = 1;

        if (base < 0) {
            base = -base;
            if (exp % 2 != 0) {
                signo = -1;
            }
        }

        int res = 1;

        for (int i = 0; i < exp; i++) {
            int temp = 0;
            for (int j = 0; j < base; j++) {
                temp += res;
            }
            res = temp;
        }

        return res * signo;
    }
};

class P6Sobreescritura : public Programa {
private:
    int x;
    int y;

public:
    P6Sobreescritura(int x, int y) {
        this->x = x;
        this->y = y;
    }

    ResultadoPrograma ejecutar() {
        CalculadoraNuevaP6 c;
        c.setValores(x, y);

        stringstream entrada;
        entrada << "Base: " << x << "\n";
        entrada << "Numero: " << y;

        stringstream salida;
        salida << "Multiplicacion (sumas sucesivas): " << c.multiplicar() << "\n";
        if (y == 0) salida << "Division: no se puede dividir entre cero\n";
        else salida << "Division (restas sucesivas): " << c.dividir() << "\n";

        if (y < 0) salida << "Potencia: no se soportan exponentes negativos";
        else salida << "Potencia (multiplicaciones sucesivas): " << c.potencia();

        return ResultadoPrograma(
            "P6 - Sobreescritura",
            "CalculadoraNueva sobrescribe los metodos multiplicar, dividir y potencia.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
