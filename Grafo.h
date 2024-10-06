#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <utility>

using namespace std;

class Grafo {
public:
    Grafo(int n);  // Constructor que toma el número de vértices
    std::vector<int> busquedaAmplitud(int inicio, int destino);
    std::vector<int> busquedaProfundidad(int inicio, int destino);
    int getNumVertices() const;
    void agregarArista(int origen, int destino, double costo);

    void imprimirAristas() const;  // Declaración de la función

    // Función para obtener el costo de una arista entre dos vértices
    double obtenerCostoArista(int origen, int destino) const;

private:
    int numVertices;
    std::vector<std::list<std::pair<int, double>>> listaAdyacencia;
    void dfsRecursivo(int actual, int destino, std::vector<bool>& visitado, std::vector<int>& predecesor);
};

#endif
