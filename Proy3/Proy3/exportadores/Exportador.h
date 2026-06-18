#ifndef EXPORTADOR_H
#define EXPORTADOR_H

#include "../mod/ResultadoPrograma.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Exportador {
private:
    static void crearCarpetas() {
        system("mkdir archivos_exportados 2>nul");
        system("mkdir archivos_exportados\\txt 2>nul");
        system("mkdir archivos_exportados\\csv 2>nul");
        system("mkdir archivos_exportados\\json 2>nul");
        system("mkdir archivos_exportados\\xml 2>nul");
        system("mkdir archivos_exportados\\html 2>nul");
    }

    static string limpiarNombre(string nombre) {
        string limpio = "";
        for (int i = 0; i < (int)nombre.length(); i++) {
            char c = nombre[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                limpio += c;
            } else {
                limpio += '_';
            }
        }
        return limpio;
    }

    static string escaparJSON(string texto) {
        string r = "";
        for (int i = 0; i < (int)texto.length(); i++) {
            char c = texto[i];
            if (c == '\\') r += "\\\\";
            else if (c == '"') r += "\\\"";
            else if (c == '\n') r += "\\n";
            else if (c != '\r') r += c;
        }
        return r;
    }

    static string escaparXML(string texto) {
        string r = "";
        for (int i = 0; i < (int)texto.length(); i++) {
            char c = texto[i];
            if (c == '&') r += "&amp;";
            else if (c == '<') r += "&lt;";
            else if (c == '>') r += "&gt;";
            else if (c == '"') r += "&quot;";
            else if (c == '\'') r += "&apos;";
            else r += c;
        }
        return r;
    }

public:
    static void guardarTXT(ResultadoPrograma r) {
        crearCarpetas();
        string ruta = "archivos_exportados\\txt\\" + limpiarNombre(r.getNombrePrograma()) + ".txt";
        ofstream archivo(ruta.c_str());

        archivo << "Programa: " << r.getNombrePrograma() << "\n";
        archivo << "Descripcion: " << r.getDescripcion() << "\n\n";
        archivo << "Datos de entrada:\n" << r.getDatosEntrada() << "\n\n";
        archivo << "Resultado:\n" << r.getResultado() << "\n";

        archivo.close();
    }

    static void guardarCSV(ResultadoPrograma r) {
        crearCarpetas();
        string ruta = "archivos_exportados\\csv\\" + limpiarNombre(r.getNombrePrograma()) + ".csv";
        ofstream archivo(ruta.c_str());

        archivo << "Campo,Valor\n";
        archivo << "Programa,\"" << r.getNombrePrograma() << "\"\n";
        archivo << "Descripcion,\"" << r.getDescripcion() << "\"\n";
        archivo << "Datos de entrada,\"" << r.getDatosEntrada() << "\"\n";
        archivo << "Resultado,\"" << r.getResultado() << "\"\n";

        archivo.close();
    }

    static void guardarJSON(ResultadoPrograma r) {
        crearCarpetas();
        string ruta = "archivos_exportados\\json\\" + limpiarNombre(r.getNombrePrograma()) + ".json";
        ofstream archivo(ruta.c_str());

        archivo << "{\n";
        archivo << "  \"programa\": \"" << escaparJSON(r.getNombrePrograma()) << "\",\n";
        archivo << "  \"descripcion\": \"" << escaparJSON(r.getDescripcion()) << "\",\n";
        archivo << "  \"datosEntrada\": \"" << escaparJSON(r.getDatosEntrada()) << "\",\n";
        archivo << "  \"resultado\": \"" << escaparJSON(r.getResultado()) << "\"\n";
        archivo << "}\n";

        archivo.close();
    }

    static void guardarXML(ResultadoPrograma r) {
        crearCarpetas();
        string ruta = "archivos_exportados\\xml\\" + limpiarNombre(r.getNombrePrograma()) + ".xml";
        ofstream archivo(ruta.c_str());

        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        archivo << "<programa>\n";
        archivo << "    <nombre>" << escaparXML(r.getNombrePrograma()) << "</nombre>\n";
        archivo << "    <descripcion>" << escaparXML(r.getDescripcion()) << "</descripcion>\n";
        archivo << "    <datosEntrada>" << escaparXML(r.getDatosEntrada()) << "</datosEntrada>\n";
        archivo << "    <resultado>" << escaparXML(r.getResultado()) << "</resultado>\n";
        archivo << "</programa>\n";

        archivo.close();
    }

    static void guardarHTML(ResultadoPrograma r) {
        crearCarpetas();
        string ruta = "archivos_exportados\\html\\" + limpiarNombre(r.getNombrePrograma()) + ".html";
        ofstream archivo(ruta.c_str());

        archivo << "<!DOCTYPE html>\n";
        archivo << "<html lang=\"es\">\n";
        archivo << "<head>\n";
        archivo << "    <meta charset=\"UTF-8\">\n";
        archivo << "    <title>" << escaparXML(r.getNombrePrograma()) << "</title>\n";
        archivo << "</head>\n";
        archivo << "<body>\n";
        archivo << "    <h1>" << escaparXML(r.getNombrePrograma()) << "</h1>\n";
        archivo << "    <h3>Descripcion</h3><p>" << escaparXML(r.getDescripcion()) << "</p>\n";
        archivo << "    <h3>Datos de entrada</h3><pre>" << escaparXML(r.getDatosEntrada()) << "</pre>\n";
        archivo << "    <h3>Resultado</h3><pre>" << escaparXML(r.getResultado()) << "</pre>\n";
        archivo << "</body>\n";
        archivo << "</html>\n";

        archivo.close();
    }
};

#endif
