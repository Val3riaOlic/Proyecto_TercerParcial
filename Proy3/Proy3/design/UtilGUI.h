#ifndef UTILGUI_H
#define UTILGUI_H

#include <windows.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../mod/ResultadoPrograma.h"
#include "../exportadores/Exportador.h"

using namespace std;

class UtilGUI {
private:
    static HWND hEdit;
    static bool dialogoTerminado;
    static bool dialogoAceptado;
    static string valorCapturado;

    static LRESULT CALLBACK InputProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
            case WM_CREATE: {
                string *datos = (string*) ((LPCREATESTRUCT)lParam)->lpCreateParams;
                string etiqueta = datos[0];
                string valorInicial = datos[1];

                CreateWindow("STATIC", etiqueta.c_str(), WS_VISIBLE | WS_CHILD | SS_LEFT,
                             20, 20, 330, 25, hwnd, NULL, NULL, NULL);

                hEdit = CreateWindow("EDIT", valorInicial.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                     20, 55, 330, 25, hwnd, NULL, NULL, NULL);

                CreateWindow("BUTTON", "Aceptar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                             65, 105, 100, 32, hwnd, (HMENU)1, NULL, NULL);

                CreateWindow("BUTTON", "Cancelar", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                             195, 105, 100, 32, hwnd, (HMENU)2, NULL, NULL);

                SetFocus(hEdit);
                break;
            }

            case WM_COMMAND:
                if (LOWORD(wParam) == 1) {
                    char texto[256];
                    GetWindowText(hEdit, texto, 256);
                    valorCapturado = texto;
                    dialogoAceptado = true;
                    dialogoTerminado = true;
                    DestroyWindow(hwnd);
                } else if (LOWORD(wParam) == 2) {
                    dialogoAceptado = false;
                    dialogoTerminado = true;
                    DestroyWindow(hwnd);
                }
                break;

            case WM_CLOSE:
                dialogoAceptado = false;
                dialogoTerminado = true;
                DestroyWindow(hwnd);
                break;

            default:
                return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        return 0;
    }

    static void registrarInputBox(HINSTANCE hInst) {
        static bool registrado = false;
        if (registrado) return;

        WNDCLASS wc = {0};
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hInstance = hInst;
        wc.lpszClassName = "InputBoxProy3";
        wc.lpfnWndProc = InputProc;
        RegisterClass(&wc);
        registrado = true;
    }

public:
    static string pedirTexto(HWND padre, string titulo, string etiqueta, string valorInicial, bool &ok) {
        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(padre, GWLP_HINSTANCE);
        registrarInputBox(hInst);

        dialogoTerminado = false;
        dialogoAceptado = false;
        valorCapturado = "";

        string datos[2];
        datos[0] = etiqueta;
        datos[1] = valorInicial;

        EnableWindow(padre, FALSE);

        HWND hwnd = CreateWindow("InputBoxProy3", titulo.c_str(), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
                                 520, 260, 390, 190, padre, NULL, hInst, datos);

        MSG msg;
        while (!dialogoTerminado && GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        EnableWindow(padre, TRUE);
        SetForegroundWindow(padre);

        ok = dialogoAceptado;
        return valorCapturado;
    }

    static int pedirEntero(HWND padre, string etiqueta, int valorInicial, bool &ok) {
        stringstream ss;
        ss << valorInicial;
        string texto = pedirTexto(padre, "Captura de dato", etiqueta, ss.str(), ok);
        if (!ok) return 0;
        return atoi(texto.c_str());
    }

    static float pedirFloat(HWND padre, string etiqueta, float valorInicial, bool &ok) {
        stringstream ss;
        ss << valorInicial;
        string texto = pedirTexto(padre, "Captura de dato", etiqueta, ss.str(), ok);
        if (!ok) return 0;
        return (float)atof(texto.c_str());
    }

    static void mostrarResultadoYExportar(HWND padre, ResultadoPrograma resultado) {
        stringstream mensaje;
        mensaje << "Programa ejecutado correctamente.\n\n";
        mensaje << "Datos de entrada:\n" << resultado.getDatosEntrada() << "\n\n";
        mensaje << "Resultado:\n" << resultado.getResultado();

        MessageBox(padre, mensaje.str().c_str(), resultado.getNombrePrograma().c_str(), MB_OK | MB_ICONINFORMATION);

        bool ok;
        string formato = pedirTexto(
            padre,
            "Exportar resultado",
            "Formato: TXT, CSV, JSON, XML, HTML, TODOS o NO",
            "TODOS",
            ok
        );

        if (!ok) return;

        transform(formato.begin(), formato.end(), formato.begin(), ::toupper);

        if (formato == "NO" || formato == "N") return;

        if (formato == "TXT") Exportador::guardarTXT(resultado);
        else if (formato == "CSV") Exportador::guardarCSV(resultado);
        else if (formato == "JSON") Exportador::guardarJSON(resultado);
        else if (formato == "XML") Exportador::guardarXML(resultado);
        else if (formato == "HTML") Exportador::guardarHTML(resultado);
        else {
            Exportador::guardarTXT(resultado);
            Exportador::guardarCSV(resultado);
            Exportador::guardarJSON(resultado);
            Exportador::guardarXML(resultado);
            Exportador::guardarHTML(resultado);
        }

        MessageBox(padre, "Archivo(s) exportado(s) correctamente.\nRevisa la carpeta archivos_exportados.",
                   "Exportacion", MB_OK | MB_ICONINFORMATION);
    }
};

HWND UtilGUI::hEdit = NULL;
bool UtilGUI::dialogoTerminado = false;
bool UtilGUI::dialogoAceptado = false;
string UtilGUI::valorCapturado = "";

#endif
