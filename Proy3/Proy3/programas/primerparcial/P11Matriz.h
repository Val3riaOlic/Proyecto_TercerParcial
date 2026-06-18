#ifndef P11MATRIZ_H
#define P11MATRIZ_H

#include "../../mod/Programa.h"
#include <sstream>
using namespace std;

class MatrizP11 {
private:
    int m[5][5];

public:
    MatrizP11() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                m[i][j] = 0;
    }

    void setValor(int i, int j, int valor) {
        m[i][j] = valor;
    }

    int getValor(int i, int j) const {
        return m[i][j];
    }

    string mostrar() const {
        stringstream ss;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ss << m[i][j] << " ";
            }
            if (i < 4) ss << "\n";
        }
        return ss.str();
    }

    string multiplicacion(int constante) const {
        stringstream ss;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ss << m[i][j] * constante << " ";
            }
            if (i < 4) ss << "\n";
        }
        return ss.str();
    }

    string multiplicacionMatriz(const MatrizP11 &b) const {
        int r[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                r[i][j] = 0;
                for (int k = 0; k < 5; k++) {
                    r[i][j] += m[i][k] * b.getValor(k, j);
                }
            }
        }

        stringstream ss;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ss << r[i][j] << " ";
            }
            if (i < 4) ss << "\n";
        }
        return ss.str();
    }
};

class P11Matriz : public Programa {
private:
    MatrizP11 A;
    MatrizP11 B;
    int constante;

public:
    P11Matriz(int matrizA[5][5], int matrizB[5][5], int constante) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                A.setValor(i, j, matrizA[i][j]);
                B.setValor(i, j, matrizB[i][j]);
            }
        }
        this->constante = constante;
    }

    ResultadoPrograma ejecutar() {
        stringstream entrada;
        entrada << "Matriz A:\n" << A.mostrar() << "\n\n";
        entrada << "Matriz B:\n" << B.mostrar() << "\n\n";
        entrada << "Constante: " << constante;

        stringstream salida;
        salida << "Resultado de A x " << constante << ":\n";
        salida << A.multiplicacion(constante) << "\n\n";
        salida << "Resultado A * B:\n";
        salida << A.multiplicacionMatriz(B);

        return ResultadoPrograma(
            "P11 - Matriz",
            "Trabaja con dos matrices de 5x5, multiplicacion por constante y multiplicacion de matrices.",
            entrada.str(),
            salida.str()
        );
    }
};

#endif
