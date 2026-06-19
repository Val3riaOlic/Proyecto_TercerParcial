#include <iostream>
#include <cstdlib>
#include "Lib_arbol.h"

using namespace std;

void lineaSuperior() {
    cout << "\n\n+------------------------------+------------------------------+" << endl;
    cout << "|        RUTA CDMX - PUEBLA    |     CUOTA / LIBRE / MIXTA    |" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
}

void mostrarPanel(const MapaRuta& red) {
    lineaSuperior();
    cout << "  Proyecto 03 - Arbol" << endl;
    cout << "  Nodos: " << red.paradas.size()
         << "   Conexiones: " << red.tramos.size()
         << "   Sentido de calculo: CDMX -> Puebla" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "| [1] VER RED     | [2] TODOS LOS CAMINOS | [3] MAS RAPIDA      |" << endl;
    cout << "| [4] MAS LENTA   | [5] CARGAR XML       | [6] CARGAR JSON      |" << endl;
    cout << "| [7] RECORRIDOS  | [8] EXPORTAR         | [0] TERMINAR         |" << endl;
    cout << "+----------------------------------------------------------------+" << endl;
    cout << "Elige opcion >> ";
}

void capturarEntero(const string& texto, int& valor) {
    cout << texto;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dato no valido, escribe un numero > ";
    }
}

void seleccionarParadas(const MapaRuta& red, int& origen, int& destino) {
    imprimirListaParadas(red);
    cout << "\nCaptura los numeros para comparar las rutas disponibles." << endl;
    capturarEntero("Origen  > ", origen);
    capturarEntero("Destino > ", destino);
}

void pedirArchivo(const string& tipo, string& archivo) {
    cout << "Nombre del archivo " << tipo << " > ";
    cin >> archivo;
}

int main() {
    MapaRuta red;
    prepararMapa(red, true, "Proyecto 03 - Arbol");
    cargarRutaTaxquenaIztacalco(red);

    int opcion = -1;
    do {
        mostrarPanel(red);
        capturarEntero("", opcion);

        switch (opcion) {
            case 1:
                pintarMapa(red);
                break;
            case 2: {
                int origen, destino;
                seleccionarParadas(red, origen, destino);
                analizarCaminos(red, origen, destino);
                break;
            }
            case 3: {
                int origen, destino;
                seleccionarParadas(red, origen, destino);
                rutaMinimaDijkstra(red, origen, destino);
                break;
            }
            case 4: {
                int origen, destino;
                seleccionarParadas(red, origen, destino);
                rutaMasLarga(red, origen, destino);
                break;
            }
            case 5: {
                string archivo;
                pedirArchivo("XML", archivo);
                leerMapaXML(red, archivo);
                break;
            }
            case 6: {
                string archivo;
                pedirArchivo("JSON", archivo);
                leerMapaJSON(red, archivo);
                break;
            }
            case 7:
                mostrarRecorridos(red);
                break;
            case 8:
                exportarArchivos(red, "arbol");
                break;
            case 0:
                cout << "\nPrograma cerrado. Ruta CDMX-Puebla finalizada." << endl;
                break;
            default:
                cout << "\nOpcion fuera del menu." << endl;
        }
    } while (opcion != 0);

    return 0;
}
