//
// Created by Erik on 1/20/2025.
//

#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <vector>
#include <string>
#include <iostream>

// Estructura que representa un paquete con información para ordenamiento.
struct PaqueteOrdenado {
    int id; // Identificador único del paquete.
    int priority; // Prioridad del paquete (criterio de ordenamiento).
    std::string description; // Descripción del contenido del paquete.
};

// Clase que implementa métodos de ordenamiento.
class Ordenamiento {
public:
    // Metodo para ordenar un vector usando QuickSort.
    static void quickSort(std::vector<PaqueteOrdenado>& paquetes, int low, int high);

    // Partición del vector para QuickSort.
    static int partition(std::vector<PaqueteOrdenado>& paquetes, int low, int high);

    // Metodo para ordenar un vector usando MergeSort.
    static void mergeSort(std::vector<PaqueteOrdenado>& paquetes, int left, int right);

    // Combina dos subvectores ordenados para MergeSort.
    static void merge(std::vector<PaqueteOrdenado>& paquetes, int left, int mid, int right);
};

#endif // ORDENAMIENTO_H