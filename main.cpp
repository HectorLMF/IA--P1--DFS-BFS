
#include <iostream>
#include <vector>
#include <string>
#include "Grafo.h"
#include "Utilidades.h"

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " <fichero_grafo> <origen> <destino>" << std::endl;
        return 1;
    }

    std::string ficheroGrafo = argv[1];
    int origen = std::stoi(argv[2]);
    int destino = std::stoi(argv[3]);

    Grafo grafo = leerGrafo(ficheroGrafo);

    if (origen < 0 || origen >= grafo.getNumVertices() || destino < 0 || destino >= grafo.getNumVertices()) {
        std::cerr << "Vértices fuera de rango. Deben estar entre 0 y " << grafo.getNumVertices() - 1 << "." << std::endl;
        return 1;
    }

    grafo.imprimirAristas();
    cout << "-------------------------------------------------------------"<< endl;

    std::vector<int> caminoBFS = grafo.busquedaAmplitud(origen, destino);
    std::vector<int> caminoDFS = grafo.busquedaProfundidad(origen, destino);

    // Imprimir camino BFS
    std::cout << "Camino BFS: ";
    for (int nodo : caminoBFS) {
        std::cout << nodo << "->";
    }
    std::cout << std::endl;

    // Calcular y mostrar costo total de BFS
    double costoTotalBFS = 0;
    for (size_t i = 0; i < caminoBFS.size() - 1; ++i) {
        costoTotalBFS += grafo.obtenerCostoArista(caminoBFS[i], caminoBFS[i + 1]);
    }
    std::cout << "Costo total BFS: " << costoTotalBFS << std::endl;
    cout << "-------------------------------------------------------------"<< endl;

    // Imprimir camino DFS
    std::cout << "Camino DFS: ";
    for (int nodo : caminoDFS) {
        std::cout << nodo << "->";
    }
    std::cout << std::endl;

    // Calcular y mostrar costo total de DFS
    double costoTotalDFS = 0;
    for (size_t i = 0; i < caminoDFS.size() - 1; ++i) {
        costoTotalDFS += grafo.obtenerCostoArista(caminoDFS[i], caminoDFS[i + 1]);
    }
    std::cout << "Costo total DFS: " << costoTotalDFS << std::endl;

    return 0;
}
