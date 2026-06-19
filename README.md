# Proyecto Tercer Parcial

Proyecto desarrollado en **C++** con interfaz gráfica para Windows.  
Este repositorio integra diferentes programas trabajados durante el curso, organizados por parcial, además de proyectos relacionados con **grafos, digrafos y árboles**.

El objetivo principal del proyecto es centralizar ejercicios de programación en una sola estructura, permitiendo ejecutar programas, consultar resultados y exportar información en diferentes formatos.

---

## Índice

- [Descripción general](#descripción-general)
- [Objetivo del proyecto](#objetivo-del-proyecto)
- [Tecnologías utilizadas](#tecnologías-utilizadas)
- [Estructura del repositorio](#estructura-del-repositorio)
- [Módulos principales](#módulos-principales)
- [Formatos de exportación](#formatos-de-exportación)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Cómo ejecutar el proyecto](#cómo-ejecutar-el-proyecto)
- [Cómo ejecutar los proyectos de grafos, digrafos y árboles](#cómo-ejecutar-los-proyectos-de-grafos-digrafos-y-árboles)
- [Funcionamiento general](#funcionamiento-general)
- [Autor](#autor)
- [Estado del proyecto](#estado-del-proyecto)

---

## Descripción general

**Proyecto Tercer Parcial** es un sistema desarrollado en C++ que reúne distintos programas académicos realizados durante el curso.

El proyecto principal se encuentra en la carpeta `Proy3/Proy3` y cuenta con una interfaz gráfica para Windows. Desde esta interfaz se pueden abrir y ejecutar programas correspondientes al primer y segundo parcial.

Además, el repositorio incluye una carpeta llamada `Grafos_Arboles`, donde se encuentran tres proyectos independientes:

- Proyecto de grafo.
- Proyecto de digrafo.
- Proyecto de árbol.

Estos proyectos permiten trabajar con estructuras de datos, rutas, conexiones y organización jerárquica de información.

---

## Objetivo del proyecto

El objetivo de este repositorio es aplicar y demostrar conocimientos de programación en C++, principalmente en los siguientes temas:

- Programación orientada a objetos.
- Uso de clases y objetos.
- Herencia.
- Modularización de código.
- Manejo de arreglos.
- Recursividad.
- Estructuras de datos.
- Pilas, colas y listas.
- Métodos de ordenamiento.
- Grafos.
- Digrafos.
- Árboles.
- Manejo de archivos.
- Exportación de información en distintos formatos.
- Creación de interfaces gráficas para Windows.

---

## Tecnologías utilizadas

- C++
- Windows API
- Dev-C++
- MinGW / GCC
- Programación orientada a objetos
- Manejo de archivos
- Estructuras de datos
- Exportación de datos

---

## Estructura del repositorio

```text
Proyecto_TercerParcial/
│
├── README.md
│
├── Proy3/
│   └── Proy3/
│       │
│       ├── main.cpp
│       ├── Proy3.dev
│       ├── Proy3.exe
│       ├── Makefile.win
│       │
│       ├── design/
│       │   ├── UtilGUI.h
│       │   ├── VentanaPrincipal.h
│       │   ├── VentanaPrimerParcial.h
│       │   └── VentanaSegundoParcial.h
│       │
│       ├── exportadores/
│       │   └── Exportador.h
│       │
│       ├── mod/
│       │   ├── Programa.h
│       │   └── ResultadoPrograma.h
│       │
│       ├── programas/
│       │   ├── primerparcial/
│       │   └── segundoparcial/
│       │
│       └── archivos_exportados/
│           ├── txt/
│           ├── csv/
│           ├── json/
│           ├── xml/
│           └── html/
│
└── Grafos_Arboles/
    │
    ├── Proyecto_01_Grafo_DevCpp/
    │   ├── main.cpp
    │   ├── F_grafo.cpp
    │   ├── Lib_grafo.h
    │   ├── Proyecto_01_Grafo.dev
    │   ├── compilar.bat
    │   ├── datos.json
    │   └── datos.xml
    │
    ├── Proyecto_02_Digrafo_DevCpp/
    │   ├── main.cpp
    │   ├── F_digrafo.cpp
    │   ├── Lib_digrafo.h
    │   ├── Proyecto_02_Digrafo.dev
    │   ├── compilar.bat
    │   ├── datos.json
    │   └── datos.xml
    │
    └── Proyecto_03_Arbol_DevCpp/
        ├── main.cpp
        ├── F_arbol.cpp
        ├── Lib_arbol.h
        ├── Proyecto_03_Arbol.dev
        ├── compilar.bat
        ├── datos.json
        └── datos.xml
```

---

## Módulos principales

### 1. Proyecto principal: Proy3

La carpeta `Proy3/Proy3` contiene la aplicación principal del repositorio.

Este proyecto funciona como un menú gráfico que permite acceder a diferentes programas realizados durante el curso.

Incluye:

- Ventana principal.
- Ventana para programas del primer parcial.
- Ventana para programas del segundo parcial.
- Clases base para ejecutar programas.
- Modelo para almacenar resultados.
- Exportador de resultados.
- Carpeta para organizar archivos generados.

---

### 2. Carpeta `design`

Esta carpeta contiene archivos relacionados con la interfaz gráfica del programa.

Algunos archivos importantes son:

- `VentanaPrincipal.h`: contiene la ventana principal del sistema.
- `VentanaPrimerParcial.h`: contiene la interfaz para acceder a los programas del primer parcial.
- `VentanaSegundoParcial.h`: contiene la interfaz para acceder a los programas del segundo parcial.
- `UtilGUI.h`: contiene funciones o utilidades para apoyar la creación de la interfaz.

---

### 3. Carpeta `mod`

Esta carpeta contiene clases base del sistema.

Incluye:

- `Programa.h`: clase base para representar un programa ejecutable.
- `ResultadoPrograma.h`: clase utilizada para almacenar y manejar los resultados generados por los programas.

---

### 4. Carpeta `programas`

Esta carpeta contiene los ejercicios organizados por parcial.

Se divide en:

```text
programas/
├── primerparcial/
└── segundoparcial/
```

#### Primer parcial

Incluye programas básicos e intermedios de programación en C++, enfocados en la práctica de:

- Sintaxis básica.
- Operaciones matemáticas.
- Uso de clases.
- Objetos.
- Herencia.
- Arreglos.
- Matrices.
- Recursividad.

#### Segundo parcial

Incluye programas relacionados con estructuras de datos y algoritmos, como:

- Pilas.
- Colas.
- Listas.
- Arreglos.
- Ordenamiento burbuja.
- Merge sort.
- Quick sort.
- Manejo de nuevos tipos de datos.

---

### 5. Carpeta `exportadores`

Esta carpeta contiene el módulo encargado de exportar los resultados generados por los programas.

El archivo principal es:

```text
Exportador.h
```

Este módulo permite guardar información en diferentes formatos para facilitar su consulta posterior.

---

### 6. Carpeta `archivos_exportados`

En esta carpeta se almacenan los archivos generados por el sistema.

Está organizada por formatos:

```text
archivos_exportados/
├── txt/
├── csv/
├── json/
├── xml/
└── html/
```

Cada subcarpeta guarda los archivos correspondientes al formato seleccionado.

---

## Proyectos de grafos, digrafos y árboles

La carpeta `Grafos_Arboles` contiene tres proyectos independientes desarrollados para Dev-C++.

---

### Proyecto 01: Grafo

Ruta del proyecto:

```text
Grafos_Arboles/Proyecto_01_Grafo_DevCpp/
```

Este proyecto trabaja con una estructura de grafo, donde los nodos se conectan entre sí sin una dirección obligatoria.

Archivos principales:

- `main.cpp`
- `F_grafo.cpp`
- `Lib_grafo.h`
- `Proyecto_01_Grafo.dev`
- `compilar.bat`
- `datos.json`
- `datos.xml`

Este módulo permite representar conexiones, analizar rutas y manejar información relacionada con un grafo.

---

### Proyecto 02: Digrafo

Ruta del proyecto:

```text
Grafos_Arboles/Proyecto_02_Digrafo_DevCpp/
```

Este proyecto trabaja con un digrafo, es decir, una estructura en la que las conexiones tienen una dirección específica.

Archivos principales:

- `main.cpp`
- `F_digrafo.cpp`
- `Lib_digrafo.h`
- `Proyecto_02_Digrafo.dev`
- `compilar.bat`
- `datos.json`
- `datos.xml`

Este módulo permite analizar conexiones dirigidas y rutas que dependen del sentido de cada enlace.

---

### Proyecto 03: Árbol

Ruta del proyecto:

```text
Grafos_Arboles/Proyecto_03_Arbol_DevCpp/
```

Este proyecto trabaja con una estructura de árbol, utilizada para representar datos de forma jerárquica.

Archivos principales:

- `main.cpp`
- `F_arbol.cpp`
- `Lib_arbol.h`
- `Proyecto_03_Arbol.dev`
- `compilar.bat`
- `datos.json`
- `datos.xml`

Este módulo permite representar relaciones padre-hijo y organizar información en niveles.

---

## Formatos de exportación

El sistema permite exportar información en los siguientes formatos:

| Formato | Descripción |
|---|---|
| TXT | Archivo de texto simple |
| CSV | Archivo compatible con hojas de cálculo |
| JSON | Formato estructurado para intercambio de datos |
| XML | Formato de marcado para datos estructurados |
| HTML | Archivo visualizable desde un navegador web |

---

## Requisitos

Para ejecutar correctamente el proyecto se recomienda contar con:

- Sistema operativo Windows.
- Dev-C++ instalado.
- Compilador MinGW/GCC.
- Git, en caso de clonar el repositorio desde consola.

---

## Instalación

Para descargar el proyecto, se puede clonar el repositorio usando Git:

```bash
git clone https://github.com/Val3riaOlic/Proyecto_TercerParcial.git
```

Después, entrar a la carpeta del repositorio:

```bash
cd Proyecto_TercerParcial
```

---

## Cómo ejecutar el proyecto

### Opción 1: Ejecutar desde Dev-C++

1. Abrir Dev-C++.
2. Seleccionar la opción para abrir un proyecto.
3. Buscar el archivo:

```text
Proy3/Proy3/Proy3.dev
```

4. Abrir el proyecto.
5. Compilar.
6. Ejecutar.

---

### Opción 2: Ejecutar el archivo `.exe`

También se puede ejecutar directamente el archivo generado:

```text
Proy3/Proy3/Proy3.exe
```

> Nota: Esta opción funciona si el archivo ejecutable ya fue compilado correctamente y el equipo cuenta con los componentes necesarios para ejecutarlo.

---

## Cómo ejecutar los proyectos de grafos, digrafos y árboles

Cada proyecto dentro de `Grafos_Arboles` puede ejecutarse de forma independiente.

---

### Ejecutar el proyecto de grafo

Abrir en Dev-C++ el archivo:

```text
Grafos_Arboles/Proyecto_01_Grafo_DevCpp/Proyecto_01_Grafo.dev
```

Después:

1. Compilar.
2. Ejecutar.
3. Usar las opciones mostradas por el programa.

---

### Ejecutar el proyecto de digrafo

Abrir en Dev-C++ el archivo:

```text
Grafos_Arboles/Proyecto_02_Digrafo_DevCpp/Proyecto_02_Digrafo.dev
```

Después:

1. Compilar.
2. Ejecutar.
3. Usar las opciones mostradas por el programa.

---

### Ejecutar el proyecto de árbol

Abrir en Dev-C++ el archivo:

```text
Grafos_Arboles/Proyecto_03_Arbol_DevCpp/Proyecto_03_Arbol.dev
```

Después:

1. Compilar.
2. Ejecutar.
3. Usar las opciones mostradas por el programa.

---

## Ejecución mediante archivo `.bat`

Los proyectos de la carpeta `Grafos_Arboles` incluyen un archivo llamado:

```text
compilar.bat
```

Este archivo puede utilizarse para compilar el proyecto desde Windows, siempre que el compilador esté correctamente instalado y configurado en el sistema.

---

## Funcionamiento general

El proyecto principal muestra una interfaz gráfica desde la cual se puede navegar entre los diferentes programas disponibles.

El flujo general del sistema es:

1. El usuario abre la aplicación.
2. Se muestra una ventana principal.
3. El usuario selecciona el parcial o programa que desea ejecutar.
4. El sistema ejecuta el programa seleccionado.
5. Se genera un resultado.
6. El resultado puede exportarse en diferentes formatos.
7. Los archivos generados se guardan en la carpeta correspondiente.

---

## Ventajas del proyecto

- Organiza varios ejercicios en un solo sistema.
- Usa programación orientada a objetos.
- Facilita la ejecución mediante una interfaz gráfica.
- Separa el código por módulos.
- Permite exportar resultados.
- Incluye proyectos adicionales de estructuras de datos.
- Mantiene una estructura clara para su revisión académica.

---

## Conceptos aplicados

Durante el desarrollo de este proyecto se aplicaron conceptos importantes de programación, como:

- Clases.
- Objetos.
- Métodos.
- Constructores.
- Herencia.
- Modularización.
- Arreglos.
- Matrices.
- Recursividad.
- Pilas.
- Colas.
- Listas.
- Ordenamiento.
- Grafos.
- Digrafos.
- Árboles.
- Archivos.
- Interfaz gráfica.

---

## Posibles errores y soluciones

### El proyecto no compila

Verificar que Dev-C++ esté instalado correctamente y que el compilador MinGW/GCC esté configurado.

---

### No se abre el archivo `.dev`

Asegurarse de abrir el proyecto desde Dev-C++ y no desde otro editor que no reconozca archivos `.dev`.

---

### El archivo `.exe` no se ejecuta

Compilar nuevamente el proyecto desde Dev-C++ para generar un ejecutable actualizado.

---

### No aparecen los archivos exportados

Verificar que existan las carpetas dentro de:

```text
Proy3/Proy3/archivos_exportados/
```

---

## Autor

Proyecto desarrollado con fines académicos para la materia de programación.

---

## Estado del proyecto

Proyecto funcional y organizado en módulos.

Incluye:

- Aplicación principal en C++.
- Interfaz gráfica para Windows.
- Programas organizados por parcial.
- Módulo de exportación.
- Proyectos independientes de grafo, digrafo y árbol.

---

## Licencia

Este repositorio no especifica una licencia.  
Su uso está orientado principalmente a fines educativos y académicos.
