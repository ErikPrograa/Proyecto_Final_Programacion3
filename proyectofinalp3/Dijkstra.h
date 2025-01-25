//
// Created by Erik on 1/20/2025.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include <iostream>
#include <limits>

// Clase que implementa el algoritmo de Dijkstra para encontrar rutas más cortas.
class Dijkstra {
public:
    // Metodo estático que calcula la distancia más corta desde un nodo de origen a todos los demás.
    static std::vector<int> rutaMasCorta(const std::vector<std::vector<int>>& grafo, int origen);
};

#endif // DIJKSTRA_H