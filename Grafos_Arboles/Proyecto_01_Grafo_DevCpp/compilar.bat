@echo off
echo Compilando Grafo...
g++ main.cpp F_grafo.cpp -o Grafo.exe
if errorlevel 1 (
    echo.
    echo Hubo errores de compilacion.
    pause
    exit /b
)
echo.
echo Compilacion terminada. Ejecutando...
echo.
Grafo.exe
pause
