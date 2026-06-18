#ifndef RESULTADOPROGRAMA_H
#define RESULTADOPROGRAMA_H

#include <string>
using namespace std;

class ResultadoPrograma {
private:
    string nombrePrograma;
    string descripcion;
    string datosEntrada;
    string resultado;

public:
    ResultadoPrograma() {
        nombrePrograma = "";
        descripcion = "";
        datosEntrada = "";
        resultado = "";
    }

    ResultadoPrograma(string nombrePrograma, string descripcion, string datosEntrada, string resultado) {
        this->nombrePrograma = nombrePrograma;
        this->descripcion = descripcion;
        this->datosEntrada = datosEntrada;
        this->resultado = resultado;
    }

    string getNombrePrograma() const {
        return nombrePrograma;
    }

    string getDescripcion() const {
        return descripcion;
    }

    string getDatosEntrada() const {
        return datosEntrada;
    }

    string getResultado() const {
        return resultado;
    }
};

#endif
