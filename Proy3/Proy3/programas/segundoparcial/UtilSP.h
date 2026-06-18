#ifndef UTILSP_H
#define UTILSP_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class UtilSP {
public:
    static string intToString(int valor) {
        stringstream ss;
        ss << valor;
        return ss.str();
    }

    static string vectorEnterosToString(const vector<int>& datos) {
        stringstream ss;
        for (size_t i = 0; i < datos.size(); i++) {
            ss << datos[i];
            if (i + 1 < datos.size()) ss << ", ";
        }
        return ss.str();
    }

    static string vectorEnterosConIndice(const vector<int>& datos) {
        stringstream ss;
        for (size_t i = 0; i < datos.size(); i++) {
            ss << "Posicion " << i << ": " << datos[i] << "\n";
        }
        return ss.str();
    }
};

#endif
