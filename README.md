# Proyecto Tercer Parcial

Proyecto desarrollado en **C++** con interfaz gráfica para Windows.  
El sistema integra diferentes programas trabajados durante el curso, organizados por parcial, y permite ejecutar cada ejercicio desde una interfaz principal.

Además, el proyecto cuenta con un módulo de exportación que guarda los resultados generados en distintos formatos: **TXT, CSV, JSON, XML y HTML**.

---

## Descripción general

Este proyecto funciona como un **convertidor y ejecutor de programas**.  
Su objetivo principal es centralizar ejercicios de programación en una sola aplicación gráfica, permitiendo:

- Abrir programas del primer parcial.
- Abrir programas del segundo parcial.
- Ejecutar ejercicios desde botones de la interfaz.
- Generar resultados mediante clases.
- Exportar la información obtenida en varios formatos.
- Organizar los archivos exportados automáticamente.

El sistema está estructurado usando **programación orientada a objetos**, separando la interfaz, los modelos de resultado, los programas y los exportadores.

---

## Tecnologías utilizadas

- C++
- Windows API
- Dev-C++
- MinGW / GCC
- Programación orientada a objetos
- Manejo de archivos
- Exportación de datos en múltiples formatos

---

## Estructura del proyecto

```text
Proyecto_TercerParcial/
│
└── Proy3/
    └── Proy3/
        │
        ├── main.cpp
        ├── Proy3.dev
        ├── Makefile.win
        │
        ├── design/
        │   ├── UtilGUI.h
        │   ├── VentanaPrincipal.h
        │   ├── VentanaPrimerParcial.h
        │   └── VentanaSegundoParcial.h
        │
        ├── exportadores/
        │   └── Exportador.h
        │
        ├── mod/
        │   ├── Programa.h
        │   └── ResultadoPrograma.h
        │
        ├── programas/
        │   ├── primerparcial/
        │   └── segundoparcial/
        │
        └── archivos_exportados/
            ├── txt/
            ├── csv/
            ├── json/
            ├── xml/
            └── html/
