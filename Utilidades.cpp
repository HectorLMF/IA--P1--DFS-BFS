#include "Utilidades.h"
#include <fstream>
#include <sstream>
#include <iostream>

Grafo leerGrafo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        exit(1);
    }

    int n;
    archivo >> n;
    Grafo grafo(n);  // Llamamos al constructor de Grafo con el número de vértices

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double distancia;
            archivo >> distancia;
            if (distancia != -1 && i != j) {
                grafo.agregarArista(i, j, distancia);  // Agregar arista
            }
        }
    }

    archivo.close();
    return grafo;
}
