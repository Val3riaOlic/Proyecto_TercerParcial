#ifndef VENTANASEGUNDOPARCIAL_H
#define VENTANASEGUNDOPARCIAL_H

#include <windows.h>
#include <vector>
#include <string>
#include <sstream>

#include "UtilGUI.h"
#include "../programas/segundoparcial/SegundoParcial.h"

using namespace std;

#define ID_SP_PILA_DB       501
#define ID_SP_PILA_NTD      502
#define ID_SP_COLA_DB       503
#define ID_SP_COLA_NTD      504
#define ID_SP_LISTA_DB      505
#define ID_SP_LISTA_NTD     506
#define ID_SP_BURBUJA_DB    507
#define ID_SP_BURBUJA_NTD   508
#define ID_SP_MERGE_DB      509
#define ID_SP_MERGE_NTD     510
#define ID_SP_QUICK_DB      511
#define ID_SP_QUICK_NTD     512
#define ID_SP_REGRESAR      599

class VentanaSegundoParcial {
private:
    static bool claseRegistrada;

    static vector<int> pedirVectorEnteros(HWND hwnd, string titulo, int cantidad, int inicial) {
        vector<int> valores;
        bool ok;

        for (int i = 0; i < cantidad; i++) {
            stringstream etiqueta;
            etiqueta << titulo << " " << (i + 1) << ":";

            int valor = UtilGUI::pedirEntero(hwnd, etiqueta.str(), inicial + i, ok);

            if (!ok) {
                valores.clear();
                return valores;
            }

            valores.push_back(valor);
        }

        return valores;
    }

    static vector<PersonaSP> pedirVectorPersonas(HWND hwnd, int cantidad) {
        vector<PersonaSP> personas;
        bool ok;

        for (int i = 0; i < cantidad; i++) {
            stringstream tituloNombre;
            tituloNombre << "Nombre de persona " << (i + 1) << ":";

            string nombre = UtilGUI::pedirTexto(
                hwnd,
                "Captura de persona",
                tituloNombre.str(),
                "Persona",
                ok
            );

            if (!ok) {
                personas.clear();
                return personas;
            }

            stringstream tituloEdad;
            tituloEdad << "Edad de persona " << (i + 1) << ":";

            int edad = UtilGUI::pedirEntero(
                hwnd,
                tituloEdad.str(),
                20 + i,
                ok
            );

            if (!ok) {
                personas.clear();
                return personas;
            }

            personas.push_back(PersonaSP(nombre, edad));
        }

        return personas;
    }

    static vector<int> datosDemo() {
        vector<int> numeros;
        numeros.push_back(8);
        numeros.push_back(4);
        numeros.push_back(10);
        numeros.push_back(2);
        numeros.push_back(6);
        return numeros;
    }

    static vector<PersonaSP> personasDemo() {
        vector<PersonaSP> personas;
        personas.push_back(PersonaSP("Ana", 20));
        personas.push_back(PersonaSP("Luis", 18));
        personas.push_back(PersonaSP("Carlos", 25));
        personas.push_back(PersonaSP("Maria", 21));
        return personas;
    }

    static void ejecutarPilaDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ingresar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        PilaArregloDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarPilaNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ingresar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        PilaArregloNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarColaDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ingresar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        ColaArregloDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarColaNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ingresar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        ColaArregloNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarListaDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ingresar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        ListaArregloDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarListaNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ingresar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        ListaArregloNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarBurbujaDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ordenar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        BurbujaDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarBurbujaNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ordenar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        BurbujaNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarMergeDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ordenar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        MergeDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarMergeNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ordenar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        MergeNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarQuickDB(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantos numeros deseas ordenar?", 5, ok);
        if (!ok) return;

        vector<int> datos = pedirVectorEnteros(hwnd, "Numero", cantidad, 1);
        if (datos.empty()) return;

        QuickDB programa(datos);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarQuickNTD(HWND hwnd) {
        bool ok;
        int cantidad = UtilGUI::pedirEntero(hwnd, "Cuantas personas deseas ordenar?", 4, ok);
        if (!ok) return;

        vector<PersonaSP> personas = pedirVectorPersonas(hwnd, cantidad);
        if (personas.empty()) return;

        QuickNTD programa(personas);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void crearControles(HWND hwnd) {
        CreateWindow(
            "STATIC",
            "PROGRAMAS DEL SEGUNDO PARCIAL",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            0, 20, 760, 35,
            hwnd,
            NULL,
            NULL,
            NULL
        );

        const char* textos[] = {
            "Pila DB",
            "Pila NTD",
            "Cola DB",
            "Cola NTD",
            "Lista DB",
            "Lista NTD",
            "Burbuja DB",
            "Burbuja NTD",
            "Merge DB",
            "Merge NTD",
            "Quick DB",
            "Quick NTD"
        };

        int ids[] = {
            ID_SP_PILA_DB,
            ID_SP_PILA_NTD,
            ID_SP_COLA_DB,
            ID_SP_COLA_NTD,
            ID_SP_LISTA_DB,
            ID_SP_LISTA_NTD,
            ID_SP_BURBUJA_DB,
            ID_SP_BURBUJA_NTD,
            ID_SP_MERGE_DB,
            ID_SP_MERGE_NTD,
            ID_SP_QUICK_DB,
            ID_SP_QUICK_NTD
        };

        int x1 = 70;
        int x2 = 295;
        int x3 = 520;
        int y = 80;

        for (int i = 0; i < 12; i++) {
            int col = i % 3;
            int fila = i / 3;

            int x = (col == 0 ? x1 : (col == 1 ? x2 : x3));

            CreateWindow(
                "BUTTON",
                textos[i],
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                x,
                y + fila * 60,
                180,
                38,
                hwnd,
                (HMENU)ids[i],
                NULL,
                NULL
            );
        }

        CreateWindow(
            "STATIC",
            "DB = Dato Basico     NTD = Nuevo Tipo de Dato",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            120, 340, 520, 30,
            hwnd,
            NULL,
            NULL,
            NULL
        );

        CreateWindow(
            "BUTTON",
            "Cerrar",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            300, 400, 180, 38,
            hwnd,
            (HMENU)ID_SP_REGRESAR,
            NULL,
            NULL
        );
    }

    static LRESULT CALLBACK Proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
            case WM_CREATE:
                crearControles(hwnd);
                break;

            case WM_COMMAND:
                switch (LOWORD(wParam)) {
                    case ID_SP_PILA_DB: ejecutarPilaDB(hwnd); break;
                    case ID_SP_PILA_NTD: ejecutarPilaNTD(hwnd); break;
                    case ID_SP_COLA_DB: ejecutarColaDB(hwnd); break;
                    case ID_SP_COLA_NTD: ejecutarColaNTD(hwnd); break;
                    case ID_SP_LISTA_DB: ejecutarListaDB(hwnd); break;
                    case ID_SP_LISTA_NTD: ejecutarListaNTD(hwnd); break;
                    case ID_SP_BURBUJA_DB: ejecutarBurbujaDB(hwnd); break;
                    case ID_SP_BURBUJA_NTD: ejecutarBurbujaNTD(hwnd); break;
                    case ID_SP_MERGE_DB: ejecutarMergeDB(hwnd); break;
                    case ID_SP_MERGE_NTD: ejecutarMergeNTD(hwnd); break;
                    case ID_SP_QUICK_DB: ejecutarQuickDB(hwnd); break;
                    case ID_SP_QUICK_NTD: ejecutarQuickNTD(hwnd); break;
                    case ID_SP_REGRESAR: DestroyWindow(hwnd); break;
                }
                break;

            case WM_CLOSE:
                DestroyWindow(hwnd);
                break;

            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }

        return 0;
    }

public:
    static void registrar(HINSTANCE hInst) {
        if (claseRegistrada) return;

        WNDCLASS wc = {0};

        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hInstance = hInst;
        wc.lpszClassName = "VentanaSegundoParcialProy3";
        wc.lpfnWndProc = Proc;

        RegisterClass(&wc);

        claseRegistrada = true;
    }

    static void abrir(HWND padre) {
        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(padre, GWLP_HINSTANCE);

        registrar(hInst);

        CreateWindow(
            "VentanaSegundoParcialProy3",
            "Segundo Parcial - Programas",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            330, 130, 820, 520,
            padre,
            NULL,
            hInst,
            NULL
        );
    }
};

bool VentanaSegundoParcial::claseRegistrada = false;

#endif
