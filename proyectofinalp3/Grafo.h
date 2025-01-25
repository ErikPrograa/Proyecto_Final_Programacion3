//
// Created by Erik on 1/20/2025.
//

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <limits> // Biblioteca estándar para manejar límites numéricos.
#include <queue> // Biblioteca para manejar colas de prioridad.

// Clase que implementa un grafo ponderado utilizando una matriz de adyacencia.
class Grafo {
private:
    int vertices; // Número de vértices en el grafo.
    std::vector<std::vector<int>> adjMatrix; // Matriz de adyacencia para almacenar pesos de aristas.

public:
    Grafo(int vertices); // Constructor que inicializa el grafo con el número de vértices.
    void agregarArista(int origen, int destino, int peso); // Agrega una arista con peso al grafo.
    void mostrarGrafo() const; // Muestra la matriz de adyacencia del grafo.
    const std::vector<std::vector<int>>& getAdjMatrix() const; // Devuelve la matriz de adyacencia.
};

#endif // GRAFO_H