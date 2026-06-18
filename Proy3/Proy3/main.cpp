#include <windows.h>
#include "design/VentanaPrincipal.h"
#include "design/VentanaSegundoParcial.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    VentanaPrincipal::mostrar(hInst);
    


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
