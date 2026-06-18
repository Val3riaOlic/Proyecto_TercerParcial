#ifndef VENTANAPRIMERPARCIAL_H
#define VENTANAPRIMERPARCIAL_H

#include <windows.h>
#include <vector>
#include <string>
#include <sstream>
#include "UtilGUI.h"
#include "../programas/primerparcial/PrimerParcial.h"

using namespace std;

#define ID_P1   201
#define ID_P2   202
#define ID_P3   203
#define ID_P4   204
#define ID_P5   205
#define ID_P6   206
#define ID_P7   207
#define ID_P8   208
#define ID_P9   209
#define ID_P10  210
#define ID_P11  211
#define ID_P12  212
#define ID_P13  213
#define ID_P14  214
#define ID_P14B 215
#define ID_REGRESAR_PRIMERO 299

class VentanaPrimerParcial {
private:
    static bool claseRegistrada;

    static void ejecutarP1(HWND hwnd) {
        P1HolaMundo programa;
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP2(HWND hwnd) {
        bool ok;
        float a = UtilGUI::pedirFloat(hwnd, "Numero 1:", 5, ok); if (!ok) return;
        float b = UtilGUI::pedirFloat(hwnd, "Numero 2:", 8, ok); if (!ok) return;
        P2Suma programa(a, b);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP3(HWND hwnd) {
        bool ok;
        int op = UtilGUI::pedirEntero(hwnd, "Operacion 1=Suma, 2=Resta, 3=Multiplicacion, 4=Division:", 1, ok); if (!ok) return;
        float a = UtilGUI::pedirFloat(hwnd, "Numero 1:", 10, ok); if (!ok) return;
        float b = UtilGUI::pedirFloat(hwnd, "Numero 2:", 5, ok); if (!ok) return;
        P3CalculadoraBasica programa(op, a, b);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP4(HWND hwnd) {
        bool ok;
        int op = UtilGUI::pedirEntero(hwnd, "Operacion 1=Suma, 2=Resta, 3=Multiplicacion, 4=Division:", 1, ok); if (!ok) return;
        int parametros = UtilGUI::pedirEntero(hwnd, "Cuantos parametros? 2 o 3:", 3, ok); if (!ok) return;
        float a = UtilGUI::pedirFloat(hwnd, "Numero 1:", 10, ok); if (!ok) return;
        float b = UtilGUI::pedirFloat(hwnd, "Numero 2:", 5, ok); if (!ok) return;
        float c = 0;
        if (parametros == 3) { c = UtilGUI::pedirFloat(hwnd, "Numero 3:", 2, ok); if (!ok) return; }
        P4CalculadoraConVariantes programa(op, parametros, a, b, c);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP5(HWND hwnd) {
        bool ok;
        int x = UtilGUI::pedirEntero(hwnd, "Valor X:", 8, ok); if (!ok) return;
        int y = UtilGUI::pedirEntero(hwnd, "Valor Y:", 4, ok); if (!ok) return;
        P5Herencia programa(x, y);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP6(HWND hwnd) {
        bool ok;
        int x = UtilGUI::pedirEntero(hwnd, "Valor X:", 8, ok); if (!ok) return;
        int y = UtilGUI::pedirEntero(hwnd, "Valor Y:", 4, ok); if (!ok) return;
        P6Sobreescritura programa(x, y);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP7(HWND hwnd) {
        bool ok;
        float precioPE = UtilGUI::pedirFloat(hwnd, "Precio auto PE:", 150000, ok); if (!ok) return;
        int anioPE = UtilGUI::pedirEntero(hwnd, "Anio auto PE:", 2018, ok); if (!ok) return;
        float precioPOO = UtilGUI::pedirFloat(hwnd, "Precio auto POO:", 220000, ok); if (!ok) return;
        int anioPOO = UtilGUI::pedirEntero(hwnd, "Anio auto POO:", 2022, ok); if (!ok) return;
        string nombre = UtilGUI::pedirTexto(hwnd, "Captura de dato", "Nombre:", "Edgar", ok); if (!ok) return;
        string ap = UtilGUI::pedirTexto(hwnd, "Captura de dato", "Apellido paterno:", "Verboonen", ok); if (!ok) return;
        string am = UtilGUI::pedirTexto(hwnd, "Captura de dato", "Apellido materno:", "Sierra", ok); if (!ok) return;
        string genero = UtilGUI::pedirTexto(hwnd, "Captura de dato", "Genero:", "Masculino", ok); if (!ok) return;
        int edad = UtilGUI::pedirEntero(hwnd, "Edad:", 20, ok); if (!ok) return;
        P7PEPOO programa(precioPE, anioPE, precioPOO, anioPOO, nombre, ap, am, genero, edad);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static vector<double> pedirVectorDouble(HWND hwnd, string titulo, int cantidad, double inicial) {
        vector<double> valores;
        bool ok;
        for (int i = 0; i < cantidad; i++) {
            stringstream etiqueta; etiqueta << titulo << " " << (i + 1) << ":";
            float v = UtilGUI::pedirFloat(hwnd, etiqueta.str(), (float)(inicial + i), ok);
            if (!ok) { valores.clear(); return valores; }
            valores.push_back(v);
        }
        return valores;
    }

    static vector<float> pedirVectorFloat(HWND hwnd, string titulo, int cantidad, float inicial) {
        vector<float> valores;
        bool ok;
        for (int i = 0; i < cantidad; i++) {
            stringstream etiqueta; etiqueta << titulo << " " << (i + 1) << ":";
            float v = UtilGUI::pedirFloat(hwnd, etiqueta.str(), inicial + i, ok);
            if (!ok) { valores.clear(); return valores; }
            valores.push_back(v);
        }
        return valores;
    }

    static void ejecutarP8(HWND hwnd) {
        vector<double> nums = pedirVectorDouble(hwnd, "Numero", 5, 1);
        if (nums.empty()) return;
        P8CalculadoraCincoNumeros programa(nums);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP9(HWND hwnd) {
        vector<double> nums = pedirVectorDouble(hwnd, "Valor", 5, 10);
        if (nums.empty()) return;
        P9CalculadoraArreglo programa(nums);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP10(HWND hwnd) {
        vector<float> nums = pedirVectorFloat(hwnd, "Calificacion", 5, 8);
        if (nums.empty()) return;
        P10PromedioConArreglo programa(nums);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP11(HWND hwnd) {
        bool ok;
        int constante = UtilGUI::pedirEntero(hwnd, "Constante para multiplicar matriz:", 2, ok); if (!ok) return;
        int a[5][5];
        int b[5][5];
        int contador = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                a[i][j] = contador;
                b[i][j] = contador + 25;
                contador++;
            }
        }
        P11Matriz programa(a, b, constante);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static vector<DatosAutoPersona> crearDatosDemoAutos() {
        vector<DatosAutoPersona> datos;
        for (int i = 0; i < 3; i++) {
            DatosAutoPersona d;
            d.precio = 100000 + (i * 50000);
            d.anio = 2018 + i;
            d.marca = (i == 0 ? "Nissan" : (i == 1 ? "Chevrolet" : "Toyota"));
            d.nombre = (i == 0 ? "Juan" : (i == 1 ? "Maria" : "Pedro"));
            d.ap = "Perez";
            d.am = "Lopez";
            d.genero = (i == 1 ? "Femenino" : "Masculino");
            d.edad = 20 + i;
            datos.push_back(d);
        }
        return datos;
    }

    static void ejecutarP12(HWND hwnd) {
        MessageBox(hwnd, "P12 se ejecutara con 3 registros de ejemplo para no capturar demasiados datos.", "P12", MB_OK | MB_ICONINFORMATION);
        P12AutosArregloObjetos programa(crearDatosDemoAutos());
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP13(HWND hwnd) {
        MessageBox(hwnd, "P13 se ejecutara con 3 registros de ejemplo para no capturar demasiados datos.", "P13", MB_OK | MB_ICONINFORMATION);
        P13AutosReferenciaObjetos programa(crearDatosDemoAutos());
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP14(HWND hwnd) {
        bool ok;
        int n = UtilGUI::pedirEntero(hwnd, "Numero para recursividad:", 5, ok); if (!ok) return;
        P14Recursividad programa(n);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void ejecutarP14B(HWND hwnd) {
        bool ok;
        int x = UtilGUI::pedirEntero(hwnd, "Valor X:", 8, ok); if (!ok) return;
        int y = UtilGUI::pedirEntero(hwnd, "Valor Y:", 4, ok); if (!ok) return;
        P14CalculadoraRecursiva programa(x, y);
        UtilGUI::mostrarResultadoYExportar(hwnd, programa.ejecutar());
    }

    static void crearControles(HWND hwnd) {
        CreateWindow("STATIC", "PROGRAMAS DEL PRIMER PARCIAL", WS_VISIBLE | WS_CHILD | SS_CENTER,
                     0, 20, 760, 35, hwnd, NULL, NULL, NULL);

        const char* textos[] = {
            "P1 - Hola Mundo", "P2 - Suma", "P3 - Calculadora", "P4 - Variantes",
            "P5 - Herencia", "P6 - Sobreescritura", "P7 - PE y POO", "P8 - 5 Numeros",
            "P9 - Arreglo", "P10 - Promedio", "P11 - Matriz", "P12 - Autos Objetos",
            "P13 - Autos Referencia", "P14 - Recursividad", "P14B - Calc. Recursiva"
        };

        int ids[] = { ID_P1, ID_P2, ID_P3, ID_P4, ID_P5, ID_P6, ID_P7, ID_P8, ID_P9, ID_P10, ID_P11, ID_P12, ID_P13, ID_P14, ID_P14B };

        int x1 = 50, x2 = 295, x3 = 540;
        int y = 75;
        for (int i = 0; i < 15; i++) {
            int col = i % 3;
            int fila = i / 3;
            int x = (col == 0 ? x1 : (col == 1 ? x2 : x3));
            CreateWindow("BUTTON", textos[i], WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                         x, y + fila * 55, 200, 38, hwnd, (HMENU)ids[i], NULL, NULL);
        }

        CreateWindow("BUTTON", "Cerrar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                     300, 380, 180, 38, hwnd, (HMENU)ID_REGRESAR_PRIMERO, NULL, NULL);
    }

    static LRESULT CALLBACK Proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
            case WM_CREATE:
                crearControles(hwnd);
                break;

            case WM_COMMAND:
                switch (LOWORD(wParam)) {
                    case ID_P1: ejecutarP1(hwnd); break;
                    case ID_P2: ejecutarP2(hwnd); break;
                    case ID_P3: ejecutarP3(hwnd); break;
                    case ID_P4: ejecutarP4(hwnd); break;
                    case ID_P5: ejecutarP5(hwnd); break;
                    case ID_P6: ejecutarP6(hwnd); break;
                    case ID_P7: ejecutarP7(hwnd); break;
                    case ID_P8: ejecutarP8(hwnd); break;
                    case ID_P9: ejecutarP9(hwnd); break;
                    case ID_P10: ejecutarP10(hwnd); break;
                    case ID_P11: ejecutarP11(hwnd); break;
                    case ID_P12: ejecutarP12(hwnd); break;
                    case ID_P13: ejecutarP13(hwnd); break;
                    case ID_P14: ejecutarP14(hwnd); break;
                    case ID_P14B: ejecutarP14B(hwnd); break;
                    case ID_REGRESAR_PRIMERO: DestroyWindow(hwnd); break;
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
        wc.lpszClassName = "VentanaPrimerParcialProy3";
        wc.lpfnWndProc = Proc;
        RegisterClass(&wc);
        claseRegistrada = true;
    }

    static void abrir(HWND padre) {
        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(padre, GWLP_HINSTANCE);
        registrar(hInst);
        CreateWindow("VentanaPrimerParcialProy3", "Primer Parcial - Programas",
                     WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                     330, 130, 820, 500, padre, NULL, hInst, NULL);
    }
};

bool VentanaPrimerParcial::claseRegistrada = false;

#endif
