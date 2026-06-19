@echo off
echo Compilando Arbol...
g++ main.cpp F_arbol.cpp -o Arbol.exe
if errorlevel 1 (
    echo.
    echo Hubo errores de compilacion.
    pause
    exit /b
)
echo.
echo Compilacion terminada. Ejecutando...
echo.
Arbol.exe
pause
