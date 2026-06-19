@echo off
echo Compilando Digrafo...
g++ main.cpp F_digrafo.cpp -o Digrafo.exe
if errorlevel 1 (
    echo.
    echo Hubo errores de compilacion.
    pause
    exit /b
)
echo.
echo Compilacion terminada. Ejecutando...
echo.
Digrafo.exe
pause
