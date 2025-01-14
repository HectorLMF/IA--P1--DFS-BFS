#include "Grafo.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;



// Constructor que inicializa el grafo con n vértices
Grafo::Grafo(int n) : numVertices(n), listaAdyacencia(n) {}

// Función para agregar una arista con un costo entre dos vértices
void Grafo::agregarArista(int origen, int destino, double costo) {
    listaAdyacencia[origen].push_back({destino, costo});
    listaAdyacencia[destino].push_back({origen, costo});  // Grafo no dirigido
}

int Grafo::getNumVertices() const {
    return numVertices;
}

// Búsqueda en Amplitud (BFS)
std::vector<int> Grafo::busquedaAmplitud(int origen, int destino) {
    std::vector<bool> visitado(numVertices, false);
    std::vector<int> predecesor(numVertices, -1);
    std::queue<int> cola;
    
    visitado[origen] = true;
    cola.push(origen);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        if (actual == destino) {
            break;
        }

        for (const auto& vecino : listaAdyacencia[actual]) {
            int v = vecino.first;
            if (!visitado[v]) {
                visitado[v] = true;
                predecesor[v] = actual;
                cola.push(v);
            }
        }
    }

    std::vector<int> camino;
    for (int v = destino; v != -1; v = predecesor[v]) {
        camino.push_back(v);
    }

    std::reverse(camino.begin(), camino.end());
    return camino;
}

// Búsqueda en Profundidad (DFS)
std::vector<int> Grafo::busquedaProfundidad(int origen, int destino) {
    std::vector<int> camino;
    std::vector<bool> visitado(numVertices, false);
    std::vector<int> predecesor(numVertices, -1);

    dfsRecursivo(origen, destino, visitado, predecesor);

    if (predecesor[destino] == -1) {
        return camino;  // Si no se encuentra un camino, devolver vacío
    }

    for (int v = destino; v != -1; v = predecesor[v]) {
        camino.push_back(v);
    }

    std::reverse(camino.begin(), camino.end());
    return camino;
}

void Grafo::dfsRecursivo(int actual, int destino, std::vector<bool>& visitado, std::vector<int>& predecesor) {
    visitado[actual] = true;

    if (actual == destino) {
        return;
    }

    for (const auto& vecino : listaAdyacencia[actual]) {
        int v = vecino.first;
        if (!visitado[v]) {
            predecesor[v] = actual;
            dfsRecursivo(v, destino, visitado, predecesor);
        }
    }
}

void Grafo::imprimirAristas() const {
    for (int i = 0; i < numVertices; ++i) {
        for (const auto& vecino : listaAdyacencia[i]) {
            int destino = vecino.first;
            double costo = vecino.second;
            if (i < destino) {  // Evitar imprimir la misma arista dos veces en un grafo no dirigido
                std::cout << "Arista: " << i << " - " << destino << " (Costo: " << costo << ")" << std::endl;
            }
        }
    }
}


double Grafo::obtenerCostoArista(int origen, int destino) const {
    for (const auto& vecino : listaAdyacencia[origen]) {
        if (vecino.first == destino) {
            return vecino.second;  // Retorna el costo de la arista
        }
    }
    return -1;  // Retorna -1 si no hay arista
}
