//
// Created by Erik on 1/20/2025.
//

#include "TablaHash.h"

// Constructor que inicializa la tabla hash con el tamaño especificado.
TablaHash::TablaHash(int tableSize) : size(tableSize) {
    table.resize(size); // Redimensiona el vector para almacenar "size" listas.
}

// Función hash que calcula el índice a partir de una clave.
int TablaHash::hashFunction(int key) const {
    return key % size; // Devuelve el residuo de dividir la clave entre el tamaño de la tabla.
}

// Metodo para insertar un paquete en la tabla.
void TablaHash::insertarPaquete(const Paquete& paquete) {
    int index = hashFunction(paquete.id); // Calcula el índice usando la función hash.
    table[index].push_back(paquete); // Agrega el paquete al final de la lista en ese índice.
}

// Metodo para buscar un paquete por su número de seguimiento.
Paquete* TablaHash::buscarPaquete(int trackingNumber) {
    int index = hashFunction(trackingNumber); // Calcula el índice usando la función hash.
    // Recorre la lista en el índice calculado.
    for (auto& paquete : table[index]) {
        if (paquete.id == trackingNumber) { // Si encuentra el paquete con el ID especificado.
            return &paquete; // Devuelve un puntero al paquete.
        }
    }
    return nullptr; // Retorna nullptr si no encuentra el paquete.
}

// Metodo para eliminar un paquete por su número de seguimiento.
void TablaHash::eliminarPaquete(int trackingNumber) {
    int index = hashFunction(trackingNumber); // Calcula el índice usando la función hash.
    // Elimina los paquetes de la lista en el índice calculado cuyo ID coincida con el especificado.
    table[index].remove_if([trackingNumber](const Paquete& paquete) {
        return paquete.id == trackingNumber;
    });
}

// Metodo para mostrar el contenido de la tabla hash.
void TablaHash::mostrarTabla() const {
    for (int i = 0; i < size; ++i) { // Itera sobre todos los índices de la tabla.
        std::cout << "Index " << i << ": "; // Muestra el índice actual.
        for (const auto& paquete : table[i]) { // Recorre cada lista en el índice actual.
            // Imprime los detalles de cada paquete en la lista.
            std::cout << "[ID: " << paquete.id
                      << ", Description: " << paquete.description
                      << ", Status: " << paquete.status << "] ";
        }
        std::cout << std::endl; // Salto de línea al finalizar cada índice.
    }
}