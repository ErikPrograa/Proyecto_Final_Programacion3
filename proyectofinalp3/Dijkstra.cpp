//
// Created by Erik on 1/20/2025.
//

#include "Dijkstra.h"

// Implementación del algoritmo de Dijkstra para encontrar rutas más cortas.
std::vector<int> Dijkstra::rutaMasCorta(const std::vector<std::vector<int>>& grafo, int origen) {
    int n = grafo.size(); // Número de nodos en el grafo.
    std::vector<int> distancias(n, std::numeric_limits<int>::max()); // Vector para almacenar distancias, inicializado con infinito.
    distancias[origen] = 0; // La distancia al nodo de origen es 0.

    // Cola de prioridad para manejar los nodos en orden de distancia mínima.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, origen}); // Inserta el nodo de origen con distancia 0.

    while (!pq.empty()) { // Mientras haya nodos en la cola de prioridad.
        int distanciaActual = pq.top().first; // Distancia del nodo actual.
        int nodoActual = pq.top().second; // Nodo actual.
        pq.pop(); // Elimina el nodo actual de la cola.

        // Si la distancia actual es mayor que la registrada, se ignora.
        if (distanciaActual > distancias[nodoActual]) continue;

        // Recorre los vecinos del nodo actual.
        for (int vecino = 0; vecino < n; ++vecino) {
            // Si hay una conexión entre el nodo actual y el vecino.
            if (grafo[nodoActual][vecino] != std::numeric_limits<int>::max()) {
                // Calcula la nueva distancia hacia el vecino.
                int nuevaDistancia = distanciaActual + grafo[nodoActual][vecino];
                // Si la nueva distancia es menor que la registrada.
                if (nuevaDistancia < distancias[vecino]) {
                    distancias[vecino] = nuevaDistancia; // Actualiza la distancia al vecino.
                    pq.push({nuevaDistancia, vecino}); // Inserta el vecino en la cola de prioridad.
                }
            }
        }
    }

    return distancias; // Devuelve las distancias mínimas desde el nodo de origen.
}