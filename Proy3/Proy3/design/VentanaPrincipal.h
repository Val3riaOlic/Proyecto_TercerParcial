#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <windows.h>
#include "VentanaPrimerParcial.h"
#include "VentanaSegundoParcial.h"

#define ID_BTN_PRIMER_PARCIAL   101
#define ID_BTN_SEGUNDO_PARCIAL  102
#define ID_BTN_EXPORTADOS       103
#define ID_BTN_SALIR            104

class VentanaPrincipal {
private:
    static HWND lblContenido;
    static bool claseRegistrada;

    static void crearControles(HWND hwnd) {
        CreateWindow(
            "STATIC",
            "PROY3 - CONVERTIDOR DE PROGRAMAS",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            0, 0, 760, 50,
            hwnd,
            NULL,
            NULL,
            NULL
        );

        CreateWindow(
            "STATIC",
            "MENU",
            WS_VISIBLE | WS_CHILD | SS_CENTER,
            20, 80, 170, 30,
            hwnd,
            NULL,
            NULL,
            NULL
        );

        CreateWindow(
            "BUTTON",
            "Primer Parcial",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            30, 130, 150, 40,
            hwnd,
            (HMENU)ID_BTN_PRIMER_PARCIAL,
            NULL,
            NULL
        );

        CreateWindow(
            "BUTTON",
            "Segundo Parcial",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            30, 185, 150, 40,
            hwnd,
            (HMENU)ID_BTN_SEGUNDO_PARCIAL,
            NULL,
            NULL
        );

        CreateWindow(
            "BUTTON",
            "Archivos Exportados",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            30, 240, 150, 40,
            hwnd,
            (HMENU)ID_BTN_EXPORTADOS,
            NULL,
            NULL
        );

        CreateWindow(
            "BUTTON",
            "Salir",
            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            30, 320, 150, 40,
            hwnd,
            (HMENU)ID_BTN_SALIR,
            NULL,
            NULL
        );

        lblContenido = CreateWindow(
            "STATIC",
            "Bienvenido al proyecto final.\n\n"
            "Esta version esta estructurada en C++ con programacion orientada a objetos.\n\n"
            "La interfaz grafica captura datos y las clases de programas procesan la informacion.\n\n"
            "Los resultados se pueden exportar a:\n\n"
            "TXT, CSV, JSON, XML y HTML.",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            230, 100, 500, 250,
            hwnd,
            NULL,
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

                    case ID_BTN_PRIMER_PARCIAL:
                        SetWindowText(
                            lblContenido,
                            "PROGRAMAS DEL PRIMER PARCIAL\n\n"
                            "Se abrira una ventana con los programas del primer parcial.\n\n"
                            "Cada boton crea un objeto del programa correspondiente,\n"
                            "ejecuta su metodo ejecutar() y genera un ResultadoPrograma."
                        );

                        VentanaPrimerParcial::abrir(hwnd);
                        break;

                    case ID_BTN_SEGUNDO_PARCIAL:
                        SetWindowText(
                            lblContenido,
                            "PROGRAMAS DEL SEGUNDO PARCIAL\n\n"
                            "Se abrira una ventana con los programas del segundo parcial.\n\n"
                            "Aqui se integran pila, cola, lista y ordenamientos."
                        );

                        VentanaSegundoParcial::abrir(hwnd);
                        break;

                    case ID_BTN_EXPORTADOS:
                        SetWindowText(
                            lblContenido,
                            "ARCHIVOS EXPORTADOS\n\n"
                            "Los resultados se guardan automaticamente en:\n\n"
                            "archivos_exportados\\txt\n"
                            "archivos_exportados\\csv\n"
                            "archivos_exportados\\json\n"
                            "archivos_exportados\\xml\n"
                            "archivos_exportados\\html"
                        );
                        break;

                    case ID_BTN_SALIR: {
                        int respuesta = MessageBox(
                            hwnd,
                            "Seguro que deseas salir?",
                            "Confirmar salida",
                            MB_YESNO | MB_ICONQUESTION
                        );

                        if (respuesta == IDYES) {
                            PostQuitMessage(0);
                        }

                        break;
                    }
                }
                break;

            case WM_DESTROY:
                PostQuitMessage(0);
                break;

            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }

        return 0;
    }

public:
    static void registrar(HINSTANCE hInst) {
        if (claseRegistrada) {
            return;
        }

        WNDCLASS wc = {0};

        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hInstance = hInst;
        wc.lpszClassName = "VentanaPrincipalProy3";
        wc.lpfnWndProc = Proc;

        RegisterClass(&wc);

        claseRegistrada = true;
    }

    static void mostrar(HINSTANCE hInst) {
        registrar(hInst);

        VentanaPrimerParcial::registrar(hInst);
        VentanaSegundoParcial::registrar(hInst);

        CreateWindow(
            "VentanaPrincipalProy3",
            "Proy3 - Convertidor de Programas",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            350, 120, 780, 480,
            NULL,
            NULL,
            hInst,
            NULL
        );
    }
};

HWND VentanaPrincipal::lblContenido = NULL;
bool VentanaPrincipal::claseRegistrada = false;

#endif
