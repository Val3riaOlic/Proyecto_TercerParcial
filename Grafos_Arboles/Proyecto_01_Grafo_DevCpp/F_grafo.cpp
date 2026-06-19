#include "Lib_grafo.h"

static int textoAEntero(const string& texto) {
    stringstream ss(texto);
    int valor = 0;
    ss >> valor;
    return valor;
}

static float textoAFloat(const string& texto) {
    stringstream ss(texto);
    float valor = 0.0f;
    ss >> valor;
    return valor;
}

static string numeroATexto(int numero) {
    stringstream ss;
    ss << numero;
    return ss.str();
}

static int posicionParada(const MapaRuta& red, int clave) {
    for (int i = 0; i < (int)red.paradas.size(); i++) {
        if (red.paradas[i].clave == clave) return i;
    }
    return -1;
}

static string nombreParada(const MapaRuta& red, int clave) {
    for (int i = 0; i < (int)red.paradas.size(); i++) {
        if (red.paradas[i].clave == clave) return red.paradas[i].nombre;
    }
    return string("Nodo ") + numeroATexto(clave);
}

static string valorXML(const string& linea, const string& etiqueta) {
    string a = "<" + etiqueta + ">";
    string b = "</" + etiqueta + ">";
    size_t inicio = linea.find(a);
    size_t fin = linea.find(b);
    if (inicio == string::npos || fin == string::npos || fin <= inicio) return "";
    inicio += a.size();
    return linea.substr(inicio, fin - inicio);
}

static string valorJSON(const string& bloque, const string& clave) {
    string buscado = "\"" + clave + "\"";
    size_t p = bloque.find(buscado);
    if (p == string::npos) return "";
    size_t dos = bloque.find(":", p);
    if (dos == string::npos) return "";
    size_t ini = dos + 1;
    while (ini < bloque.size() && (bloque[ini] == ' ' || bloque[ini] == '\n' || bloque[ini] == '\r' || bloque[ini] == '\t')) ini++;
    if (ini >= bloque.size()) return "";
    if (bloque[ini] == '"') {
        size_t fin = bloque.find("\"", ini + 1);
        if (fin == string::npos) return "";
        return bloque.substr(ini + 1, fin - ini - 1);
    }
    size_t fin = ini;
    while (fin < bloque.size() && bloque[fin] != ',' && bloque[fin] != '}') fin++;
    return bloque.substr(ini, fin - ini);
}

static bool buscarTramo(const MapaRuta& red, int origen, int destino, Tramo& tramo) {
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        if (t.origen == origen && t.destino == destino) { tramo = t; return true; }
    }
    return false;
}

static void imprimirRuta(const MapaRuta& red, const vector<int>& ruta) {
    for (int i = 0; i < (int)ruta.size(); i++) {
        cout << nombreParada(red, ruta[i]);
        if (i < (int)ruta.size() - 1) cout << " -> ";
    }
}

static void detalleRuta(const MapaRuta& red, const vector<int>& ruta) {
    cout << "  Desglose del recorrido:" << endl;
    for (int i = 0; i < (int)ruta.size() - 1; i++) {
        Tramo t;
        if (buscarTramo(red, ruta[i], ruta[i + 1], t)) {
            cout << "    " << (i + 1) << ") " << nombreParada(red, ruta[i])
                 << " => " << nombreParada(red, ruta[i + 1])
                 << "  [" << t.minutos << " min, $" << t.pesos << "]  "
                 << t.comentario << endl;
        }
    }
}

static void explorarCaminos(const MapaRuta& red, int actual, int destino, vector<int>& ruta,
                            vector<bool>& usado, float minutos, float pesos, vector<CaminoResumen>& lista) {
    if (actual == destino) {
        CaminoResumen r;
        r.recorrido = ruta;
        r.minutos = minutos;
        r.pesos = pesos;
        lista.push_back(r);
        return;
    }

    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        int vecino = -1;
        if (t.origen == actual) vecino = t.destino;

        if (vecino == -1) continue;
        int pos = posicionParada(red, vecino);
        if (pos == -1 || usado[pos]) continue;

        usado[pos] = true;
        ruta.push_back(vecino);
        explorarCaminos(red, vecino, destino, ruta, usado, minutos + t.minutos, pesos + t.pesos, lista);
        ruta.pop_back();
        usado[pos] = false;
    }
}

static vector<CaminoResumen> obtenerCaminos(const MapaRuta& red, int origen, int destino) {
    vector<CaminoResumen> lista;
    int pOrigen = posicionParada(red, origen);
    int pDestino = posicionParada(red, destino);
    if (pOrigen == -1 || pDestino == -1) return lista;

    vector<bool> usado(red.paradas.size(), false);
    vector<int> ruta;
    usado[pOrigen] = true;
    ruta.push_back(origen);
    explorarCaminos(red, origen, destino, ruta, usado, 0.0f, 0.0f, lista);
    return lista;
}

void prepararMapa(MapaRuta& red, bool esOrientado, string titulo) {
    red.paradas.clear();
    red.tramos.clear();
    red.orientado = esOrientado;
    red.titulo = titulo;
}

void registrarParada(MapaRuta& red, int clave, string nombre) {
    Parada p;
    p.clave = clave;
    p.nombre = nombre;
    red.paradas.push_back(p);
}

void registrarTramo(MapaRuta& red, int origen, int destino, string codigo, float minutos, float pesos, string comentario) {
    Tramo t;
    t.origen = origen;
    t.destino = destino;
    t.codigo = codigo;
    t.minutos = minutos;
    t.pesos = pesos;
    t.comentario = comentario;
    red.tramos.push_back(t);
}

void cargarRutaTaxquenaIztacalco(MapaRuta& red) {
    bool tipo = red.orientado;
    string titulo = red.titulo;
    prepararMapa(red, tipo, titulo);

    registrarParada(red, 0, "Ciudad de Mexico");
    registrarParada(red, 1, "Salida Zaragoza");
    registrarParada(red, 2, "Caseta San Marcos");
    registrarParada(red, 3, "Rio Frio");
    registrarParada(red, 4, "San Martin Texmelucan");
    registrarParada(red, 5, "Caseta San Martin");
    registrarParada(red, 6, "Puebla Centro");
    registrarParada(red, 7, "Chalco");
    registrarParada(red, 8, "Ixtapaluca");
    registrarParada(red, 9, "Amecameca");
    registrarParada(red, 10, "San Nicolas de los Ranchos");
    registrarParada(red, 11, "Cholula");

    registrarTramo(red, 0, 1, "cdmx_zaragoza", 15.0f, 0.0f, "Salida de CDMX por Calzada Ignacio Zaragoza");
    registrarTramo(red, 1, 2, "zaragoza_san_marcos", 25.0f, 173.0f, "Autopista Mexico-Puebla; caseta San Marcos");
    registrarTramo(red, 2, 3, "san_marcos_rio_frio", 35.0f, 0.0f, "Tramo de cuota hacia Rio Frio");
    registrarTramo(red, 3, 4, "rio_frio_san_martin", 35.0f, 0.0f, "Continuacion por autopista 150D");
    registrarTramo(red, 4, 5, "san_martin_caseta", 10.0f, 53.0f, "Caseta San Martin Texmelucan-Puebla");
    registrarTramo(red, 5, 6, "caseta_san_martin_puebla", 20.0f, 0.0f, "Entrada a Puebla por autopista");
    registrarTramo(red, 0, 7, "cdmx_chalco_libre", 35.0f, 0.0f, "Salida libre desde CDMX hacia Chalco");
    registrarTramo(red, 7, 8, "chalco_ixtapaluca_libre", 20.0f, 0.0f, "Carretera libre Chalco-Ixtapaluca");
    registrarTramo(red, 8, 9, "ixtapaluca_amecameca_libre", 45.0f, 0.0f, "Ruta libre hacia Amecameca");
    registrarTramo(red, 9, 10, "amecameca_san_nicolas_libre", 45.0f, 0.0f, "Camino libre por zona de volcanes");
    registrarTramo(red, 10, 11, "san_nicolas_cholula_libre", 40.0f, 0.0f, "Camino libre hacia Cholula");
    registrarTramo(red, 11, 6, "cholula_puebla_libre", 25.0f, 0.0f, "Entrada libre de Cholula a Puebla");
    registrarTramo(red, 7, 2, "chalco_san_marcos_mixta", 25.0f, 173.0f, "Opcion mixta: entrar a autopista por San Marcos");
    registrarTramo(red, 8, 3, "ixtapaluca_rio_frio_mixta", 50.0f, 0.0f, "Opcion mixta: continuar libre y conectar hacia Rio Frio");
    registrarTramo(red, 3, 11, "rio_frio_cholula_libre", 80.0f, 0.0f, "Desvio libre de Rio Frio hacia Cholula");
    registrarTramo(red, 4, 11, "san_martin_cholula_libre", 45.0f, 0.0f, "Opcion libre desde San Martin hacia Cholula");
    registrarTramo(red, 2, 4, "san_marcos_san_martin_directo", 65.0f, 0.0f, "Tramo directo de autopista hacia San Martin");
    registrarTramo(red, 1, 7, "zaragoza_chalco_desvio", 25.0f, 0.0f, "Desvio desde Zaragoza hacia ruta libre por Chalco");
}

void imprimirListaParadas(const MapaRuta& red) {
    cout << "\nParadas de la ruta: " << endl;
    for (int i = 0; i < (int)red.paradas.size(); i++) {
        cout << "[" << red.paradas[i].clave << "] " << red.paradas[i].nombre;
        if (i < (int)red.paradas.size() - 1) cout << "  |  ";
    }
    cout << endl;
}

void pintarMapa(const MapaRuta& red) {
    cout << "\nRED DE RUTAS CDMX - PUEBLA" << endl;
    cout << "Proyecto: " << red.titulo << "  |  Estructura: "
         << (red.orientado ? "dirigida" : "no dirigida") << endl;
    imprimirListaParadas(red);

    cout << "\nTramos cargados:" << endl;
    cout << left << setw(4) << "#" << setw(9) << "Salida" << setw(9) << "Llegada"
         << setw(12) << "Minutos" << setw(10) << "Costo" << "Descripcion" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        cout << left << setw(4) << (i + 1)
             << setw(9) << t.origen
             << setw(9) << t.destino
             << setw(12) << t.minutos
             << "$" << setw(9) << t.pesos
             << t.comentario << endl;
    }
}

void analizarCaminos(const MapaRuta& red, int origen, int destino) {
    vector<CaminoResumen> caminos = obtenerCaminos(red, origen, destino);

    cout << "\nTODOS LOS CAMINOS DISPONIBLES" << endl;
    cout << "De " << nombreParada(red, origen) << " hacia " << nombreParada(red, destino) << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    if (posicionParada(red, origen) == -1 || posicionParada(red, destino) == -1) {
        cout << "No se pudo analizar porque algun nodo no existe." << endl;
        return;
    }
    if (caminos.empty()) {
        cout << "No hay caminos disponibles entre esas paradas." << endl;
        return;
    }

    int posCorto = 0;
    int posLargo = 0;
    for (int i = 0; i < (int)caminos.size(); i++) {
        cout << "Ruta " << setw(2) << (i + 1) << " | ";
        imprimirRuta(red, caminos[i].recorrido);
        cout << "\n          Tiempo: " << caminos[i].minutos << " min   Costo: $" << caminos[i].pesos << endl;
        if (caminos[i].minutos < caminos[posCorto].minutos ||
           (caminos[i].minutos == caminos[posCorto].minutos && caminos[i].pesos < caminos[posCorto].pesos)) posCorto = i;
        if (caminos[i].minutos > caminos[posLargo].minutos ||
           (caminos[i].minutos == caminos[posLargo].minutos && caminos[i].pesos > caminos[posLargo].pesos)) posLargo = i;
    }

    cout << "\nRESULTADO - MENOR TIEMPO" << endl;
    imprimirRuta(red, caminos[posCorto].recorrido);
    cout << "\nTiempo total: " << caminos[posCorto].minutos << " min   Costo total: $" << caminos[posCorto].pesos << endl;
    detalleRuta(red, caminos[posCorto].recorrido);

    cout << "\nRESULTADO - MAYOR TIEMPO" << endl;
    imprimirRuta(red, caminos[posLargo].recorrido);
    cout << "\nTiempo total: " << caminos[posLargo].minutos << " min   Costo total: $" << caminos[posLargo].pesos << endl;
    detalleRuta(red, caminos[posLargo].recorrido);
}

void rutaMinimaDijkstra(const MapaRuta& red, int origen, int destino) {
    int n = (int)red.paradas.size();
    int ini = posicionParada(red, origen);
    int fin = posicionParada(red, destino);
    if (ini == -1 || fin == -1) {
        cout << "\nNo existe alguno de los nodos capturados." << endl;
        return;
    }

    vector<float> distancia(n, 1000000000.0f);
    vector<int> anterior(n, -1);
    vector<bool> cerrado(n, false);
    distancia[ini] = 0.0f;

    for (int vuelta = 0; vuelta < n; vuelta++) {
        int u = -1;
        float menor = 1000000000.0f;
        for (int i = 0; i < n; i++) {
            if (!cerrado[i] && distancia[i] < menor) {
                menor = distancia[i];
                u = i;
            }
        }
        if (u == -1) break;
        cerrado[u] = true;
        int idActual = red.paradas[u].clave;

        for (int i = 0; i < (int)red.tramos.size(); i++) {
            Tramo t = red.tramos[i];
            int idVecino = -1;
            if (t.origen == idActual) idVecino = t.destino;
            if (idVecino == -1) continue;
            int v = posicionParada(red, idVecino);
            if (v == -1 || cerrado[v]) continue;
            if (distancia[u] + t.minutos < distancia[v]) {
                distancia[v] = distancia[u] + t.minutos;
                anterior[v] = u;
            }
        }
    }

    cout << "\nDIJKSTRA - RUTA MAS RAPIDA" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    if (distancia[fin] >= 1000000000.0f) {
        cout << "No hay camino entre " << nombreParada(red, origen) << " y " << nombreParada(red, destino) << endl;
        return;
    }

    vector<int> ruta;
    int cursor = fin;
    while (cursor != -1) {
        ruta.insert(ruta.begin(), red.paradas[cursor].clave);
        cursor = anterior[cursor];
    }

    float costo = 0.0f;
    for (int i = 0; i < (int)ruta.size() - 1; i++) {
        Tramo t;
        if (buscarTramo(red, ruta[i], ruta[i + 1], t)) costo += t.pesos;
    }

    cout << "Recorrido elegido: ";
    imprimirRuta(red, ruta);
    cout << "\nTiempo total: " << distancia[fin] << " min   Costo total: $" << costo << endl;
    detalleRuta(red, ruta);
}

void rutaMasLarga(const MapaRuta& red, int origen, int destino) {
    vector<CaminoResumen> caminos = obtenerCaminos(red, origen, destino);
    cout << "\nRUTA CON MAYOR TIEMPO" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    if (caminos.empty()) {
        cout << "No hay caminos disponibles." << endl;
        return;
    }
    int posLargo = 0;
    for (int i = 1; i < (int)caminos.size(); i++) {
        if (caminos[i].minutos > caminos[posLargo].minutos ||
           (caminos[i].minutos == caminos[posLargo].minutos && caminos[i].pesos > caminos[posLargo].pesos)) posLargo = i;
    }
    cout << "Recorrido seleccionado: ";
    imprimirRuta(red, caminos[posLargo].recorrido);
    cout << "\nTiempo total: " << caminos[posLargo].minutos << " min   Costo total: $" << caminos[posLargo].pesos << endl;
    detalleRuta(red, caminos[posLargo].recorrido);
}

void leerMapaXML(MapaRuta& red, const string& archivo) {
    bool tipo = red.orientado;
    string titulo = red.titulo;
    prepararMapa(red, tipo, titulo);
    ifstream f(archivo.c_str());
    if (!f.is_open()) {
        cout << "\nNo se pudo abrir el XML: " << archivo << endl;
        return;
    }

    string linea;
    Tramo t;
    bool dentroTramo = false;
    while (getline(f, linea)) {
        if (linea.find("<parada>") != string::npos) {
            string clave = valorXML(linea, "clave");
            string nombre = valorXML(linea, "nombre");
            if (clave != "") registrarParada(red, textoAEntero(clave), nombre);
        } else if (linea.find("<tramo>") != string::npos) {
            dentroTramo = true;
            t.origen = 0; t.destino = 0; t.codigo = ""; t.minutos = 0; t.pesos = 0; t.comentario = "";
        } else if (linea.find("</tramo>") != string::npos) {
            if (dentroTramo) registrarTramo(red, t.origen, t.destino, t.codigo, t.minutos, t.pesos, t.comentario);
            dentroTramo = false;
        } else if (dentroTramo) {
            string v;
            v = valorXML(linea, "origen"); if (v != "") t.origen = textoAEntero(v);
            v = valorXML(linea, "destino"); if (v != "") t.destino = textoAEntero(v);
            v = valorXML(linea, "codigo"); if (v != "") t.codigo = v;
            v = valorXML(linea, "minutos"); if (v != "") t.minutos = textoAFloat(v);
            v = valorXML(linea, "pesos"); if (v != "") t.pesos = textoAFloat(v);
            v = valorXML(linea, "comentario"); if (v != "") t.comentario = v;
        }
    }
    f.close();
    cout << "\nXML cargado: " << red.paradas.size() << " paradas y " << red.tramos.size() << " tramos." << endl;
}

void leerMapaJSON(MapaRuta& red, const string& archivo) {
    bool tipo = red.orientado;
    string titulo = red.titulo;
    prepararMapa(red, tipo, titulo);
    ifstream f(archivo.c_str());
    if (!f.is_open()) {
        cout << "\nNo se pudo abrir el JSON: " << archivo << endl;
        return;
    }
    string contenido, linea;
    while (getline(f, linea)) { contenido += linea; contenido += "\n"; }
    f.close();

    size_t pParadas = contenido.find("\"paradas\"");
    if (pParadas != string::npos) {
        size_t ini = contenido.find("[", pParadas);
        size_t fin = contenido.find("]", ini);
        if (ini != string::npos && fin != string::npos) {
            string arreglo = contenido.substr(ini, fin - ini + 1);
            size_t pos = 0;
            while ((pos = arreglo.find("{", pos)) != string::npos) {
                size_t cierre = arreglo.find("}", pos);
                if (cierre == string::npos) break;
                string bloque = arreglo.substr(pos, cierre - pos + 1);
                string clave = valorJSON(bloque, "clave");
                string nombre = valorJSON(bloque, "nombre");
                if (clave != "") registrarParada(red, textoAEntero(clave), nombre);
                pos = cierre + 1;
            }
        }
    }

    size_t pTramos = contenido.find("\"tramos\"");
    if (pTramos != string::npos) {
        size_t ini = contenido.find("[", pTramos);
        size_t fin = contenido.find("]", ini);
        if (ini != string::npos && fin != string::npos) {
            string arreglo = contenido.substr(ini, fin - ini + 1);
            size_t pos = 0;
            while ((pos = arreglo.find("{", pos)) != string::npos) {
                size_t cierre = arreglo.find("}", pos);
                if (cierre == string::npos) break;
                string bloque = arreglo.substr(pos, cierre - pos + 1);
                string origen = valorJSON(bloque, "origen");
                string destino = valorJSON(bloque, "destino");
                string codigo = valorJSON(bloque, "codigo");
                string minutos = valorJSON(bloque, "minutos");
                string pesos = valorJSON(bloque, "pesos");
                string comentario = valorJSON(bloque, "comentario");
                if (origen != "" && destino != "") registrarTramo(red, textoAEntero(origen), textoAEntero(destino), codigo, textoAFloat(minutos), textoAFloat(pesos), comentario);
                pos = cierre + 1;
            }
        }
    }

    cout << "\nJSON cargado: " << red.paradas.size() << " paradas y " << red.tramos.size() << " tramos." << endl;
}

static void escribirResumenTXT(ofstream& txt, const MapaRuta& red) {
    txt << red.titulo << endl;
    txt << "Tipo: " << (red.orientado ? "Dirigido" : "No dirigido") << endl;
    txt << "\nPARADAS" << endl;
    for (int i = 0; i < (int)red.paradas.size(); i++) txt << red.paradas[i].clave << ". " << red.paradas[i].nombre << endl;
    txt << "\nTRAMOS" << endl;
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        txt << t.origen << " -> " << t.destino << " | " << t.codigo << " | " << t.minutos << " min | $" << t.pesos << " | " << t.comentario << endl;
    }
    vector<CaminoResumen> caminos = obtenerCaminos(red, 0, 6);
    txt << "\nCAMINOS DE CIUDAD DE MEXICO A PUEBLA" << endl;
    for (int i = 0; i < (int)caminos.size(); i++) {
        txt << "Camino " << (i + 1) << ": ";
        for (int j = 0; j < (int)caminos[i].recorrido.size(); j++) {
            txt << nombreParada(red, caminos[i].recorrido[j]);
            if (j < (int)caminos[i].recorrido.size() - 1) txt << " -> ";
        }
        txt << " | " << caminos[i].minutos << " min | $" << caminos[i].pesos << endl;
    }
}

void exportarArchivos(const MapaRuta& red, const string& prefijo) {
    string txtName = prefijo + "_salida.txt";
    string csvName = prefijo + "_salida.csv";
    string jsonName = prefijo + "_salida.json";
    string xmlName = prefijo + "_salida.xml";

    ofstream txt(txtName.c_str());
    escribirResumenTXT(txt, red);
    txt.close();

    ofstream csv(csvName.c_str());
    csv << "tipo,clave,nombre,origen,destino,codigo,minutos,pesos,comentario" << endl;
    for (int i = 0; i < (int)red.paradas.size(); i++) csv << "parada," << red.paradas[i].clave << ",\"" << red.paradas[i].nombre << "\",,,,,," << endl;
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        csv << "tramo,,," << t.origen << "," << t.destino << "," << t.codigo << "," << t.minutos << "," << t.pesos << ",\"" << t.comentario << "\"" << endl;
    }
    csv.close();

    ofstream json(jsonName.c_str());
    json << "{\n  \"titulo\": \"" << red.titulo << "\",\n  \"orientado\": " << (red.orientado ? "true" : "false") << ",\n  \"paradas\": [\n";
    for (int i = 0; i < (int)red.paradas.size(); i++) {
        json << "    {\"clave\":" << red.paradas[i].clave << ",\"nombre\":\"" << red.paradas[i].nombre << "\"}";
        if (i < (int)red.paradas.size() - 1) json << ",";
        json << "\n";
    }
    json << "  ],\n  \"tramos\": [\n";
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        json << "    {\"origen\":" << t.origen << ",\"destino\":" << t.destino << ",\"codigo\":\"" << t.codigo << "\",\"minutos\":" << t.minutos << ",\"pesos\":" << t.pesos << ",\"comentario\":\"" << t.comentario << "\"}";
        if (i < (int)red.tramos.size() - 1) json << ",";
        json << "\n";
    }
    json << "  ]\n}\n";
    json.close();

    ofstream xml(xmlName.c_str());
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<mapa>\n  <titulo>" << red.titulo << "</titulo>\n  <orientado>" << (red.orientado ? "true" : "false") << "</orientado>\n  <paradas>\n";
    for (int i = 0; i < (int)red.paradas.size(); i++) xml << "    <parada><clave>" << red.paradas[i].clave << "</clave><nombre>" << red.paradas[i].nombre << "</nombre></parada>\n";
    xml << "  </paradas>\n  <tramos>\n";
    for (int i = 0; i < (int)red.tramos.size(); i++) {
        Tramo t = red.tramos[i];
        xml << "    <tramo>\n      <origen>" << t.origen << "</origen>\n      <destino>" << t.destino << "</destino>\n      <codigo>" << t.codigo << "</codigo>\n      <minutos>" << t.minutos << "</minutos>\n      <pesos>" << t.pesos << "</pesos>\n      <comentario>" << t.comentario << "</comentario>\n    </tramo>\n";
    }
    xml << "  </tramos>\n</mapa>\n";
    xml.close();

    cout << "\nExportacion completada:" << endl;
    cout << "  TXT  -> " << txtName << endl;
    cout << "  CSV  -> " << csvName << endl;
    cout << "  JSON -> " << jsonName << endl;
    cout << "  XML  -> " << xmlName << endl;
}

