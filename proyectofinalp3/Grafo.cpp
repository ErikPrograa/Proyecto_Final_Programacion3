//
// Created by Erik on 1/20/2025.
//

#include "Grafo.h" // Inclusión del archivo de cabecera.

// Constructor que inicializa el grafo con el número especificado de vértices.
Grafo::Grafo(int vertices) : vertices(vertices) {
    // Redimensiona la matriz de adyacencia y la inicializa con valores máximos (INF).
    adjMatrix.resize(vertices, std::vector<int>(vertices, std::numeric_limits<int>::max()));

    // Establece los pesos de las aristas de cada vértice consigo mismo en 0.
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i][i] = 0;
    }
}

// Metodo para agregar una arista con un peso entre dos vértices.
void Grafo::agregarArista(int origen, int destino, int peso) {
    adjMatrix[origen][destino] = peso; // Establece el peso en la matriz de adyacencia.
}

// Metodo para mostrar la matriz de adyacencia del grafo.
void Grafo::mostrarGrafo() const {
    for (const auto& row : adjMatrix) { // Recorre cada fila de la matriz.
        for (int weight : row) { // Recorre cada elemento de la fila.
            if (weight == std::numeric_limits<int>::max()) { // Si el peso es INF.
                std::cout << "INF "; // Muestra "INF" para aristas inexistentes.
            } else {
                std::cout << weight << " "; // Muestra el peso de la arista.
            }
        }
        std::cout << std::endl; // Salto de línea al final de cada fila.
    }
}

// Metodo para devolver la matriz de adyacencia del grafo.
const std::vector<std::vector<int>>& Grafo::getAdjMatrix() const {
    return adjMatrix; // Devuelve la referencia constante de la matriz de adyacencia.
}