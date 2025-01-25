//
// Created by Erik on 1/20/2025.
//

#include "Ordenamiento.h"

// Metodo para ordenar un vector usando QuickSort.
void Ordenamiento::quickSort(std::vector<PaqueteOrdenado>& paquetes, int low, int high) {
    if (low < high) { // Condición base para dividir el vector.
        int pi = partition(paquetes, low, high); // Encuentra el pivote y organiza los elementos.
        quickSort(paquetes, low, pi - 1); // Ordena la parte izquierda del pivote.
        quickSort(paquetes, pi + 1, high); // Ordena la parte derecha del pivote.
    }
}

// Metodo para realizar la partición en QuickSort.
int Ordenamiento::partition(std::vector<PaqueteOrdenado>& paquetes, int low, int high) {
    int pivot = paquetes[high].priority; // Elige el último elemento como pivote.
    int i = low - 1; // Índice del menor elemento.

    for (int j = low; j < high; j++) { // Recorre los elementos del vector.
        if (paquetes[j].priority < pivot) { // Si el elemento es menor que el pivote.
            i++;
            std::swap(paquetes[i], paquetes[j]); // Intercambia los elementos.
        }
    }
    std::swap(paquetes[i + 1], paquetes[high]); // Coloca el pivote en su posición correcta.
    return i + 1; // Retorna la posición del pivote.
}

// Metodo para ordenar un vector usando MergeSort.
void Ordenamiento::mergeSort(std::vector<PaqueteOrdenado>& paquetes, int left, int right) {
    if (left < right) { // Condición base para dividir el vector.
        int mid = left + (right - left) / 2; // Encuentra el punto medio.

        mergeSort(paquetes, left, mid); // Ordena la primera mitad.
        mergeSort(paquetes, mid + 1, right); // Ordena la segunda mitad.

        merge(paquetes, left, mid, right); // Combina las mitades ordenadas.
    }
}

// Metodo para combinar dos subvectores ordenados en MergeSort.
void Ordenamiento::merge(std::vector<PaqueteOrdenado>& paquetes, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del subvector izquierdo.
    int n2 = right - mid; // Tamaño del subvector derecho.

    std::vector<PaqueteOrdenado> L(n1), R(n2); // Vectores temporales para almacenar las mitades.

    // Copia los datos en los vectores temporales.
    for (int i = 0; i < n1; i++) L[i] = paquetes[left + i];
    for (int i = 0; i < n2; i++) R[i] = paquetes[mid + 1 + i];

    int i = 0, j = 0, k = left; // Índices para recorrer los vectores.

    // Combina los datos de L y R en orden ascendente.
    while (i < n1 && j < n2) {
        if (L[i].priority <= R[j].priority) { // Si el elemento de L es menor o igual al de R.
            paquetes[k] = L[i]; // Copia el elemento de L.
            i++;
        } else {
            paquetes[k] = R[j]; // Copia el elemento de R.
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L (si los hay).
    while (i < n1) paquetes[k++] = L[i++];

    // Copia los elementos restantes de R (si los hay).
    while (j < n2) paquetes[k++] = R[j++];
}