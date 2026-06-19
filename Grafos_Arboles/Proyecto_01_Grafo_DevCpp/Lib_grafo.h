#ifndef LIB_GRAFO_H
#define LIB_GRAFO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Parada {
    int clave;
    string nombre;
};

struct Tramo {
    int origen;
    int destino;
    string codigo;
    float minutos;
    float pesos;
    string comentario;
};

struct MapaRuta {
    vector<Parada> paradas;
    vector<Tramo> tramos;
    bool orientado;
    string titulo;
};

struct CaminoResumen {
    vector<int> recorrido;
    float minutos;
    float pesos;
};

void prepararMapa(MapaRuta& red, bool esOrientado, string titulo);
void cargarRutaTaxquenaIztacalco(MapaRuta& red); // Carga ruta CDMX-Puebla
void registrarParada(MapaRuta& red, int clave, string nombre);
void registrarTramo(MapaRuta& red, int origen, int destino, string codigo, float minutos, float pesos, string comentario);
void pintarMapa(const MapaRuta& red);
void imprimirListaParadas(const MapaRuta& red);
void analizarCaminos(const MapaRuta& red, int origen, int destino);
void rutaMinimaDijkstra(const MapaRuta& red, int origen, int destino);
void rutaMasLarga(const MapaRuta& red, int origen, int destino);
void leerMapaXML(MapaRuta& red, const string& archivo);
void leerMapaJSON(MapaRuta& red, const string& archivo);
void exportarArchivos(const MapaRuta& red, const string& prefijo);

#endif
