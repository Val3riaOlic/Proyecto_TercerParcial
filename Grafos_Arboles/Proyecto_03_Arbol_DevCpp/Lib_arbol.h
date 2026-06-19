#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H

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

struct NodoBinario {
    Parada info;
    NodoBinario* izquierda;
    NodoBinario* derecha;
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

NodoBinario* nuevoNodoBinario(Parada dato);
NodoBinario* insertarPorClave(NodoBinario* raiz, Parada dato);
NodoBinario* armarArbolParadas(const MapaRuta& red);
void recorridoPreorden(NodoBinario* raiz);
void recorridoInorden(NodoBinario* raiz);
void recorridoPosorden(NodoBinario* raiz);
void mostrarRecorridos(const MapaRuta& red);
void destruirArbol(NodoBinario* raiz);

#endif
