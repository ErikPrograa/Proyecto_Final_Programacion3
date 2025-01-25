//
// Created by Erik on 1/20/2025.
//

#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Paquete.h"

// Clase que implementa una tabla hash para gestionar paquetes.
class TablaHash {
private:
    std::vector<std::list<Paquete>> table; // Vector de listas para manejar colisiones.
    int size; // Tamaño de la tabla hash.

    int hashFunction(int key) const; // Función hash que calcula el índice a partir de una clave.

public:
    TablaHash(int tableSize); // Constructor que inicializa la tabla con el tamaño especificado.
    void insertarPaquete(const Paquete& paquete); // Inserta un paquete en la tabla.
    Paquete* buscarPaquete(int trackingNumber); // Busca un paquete por su número de seguimiento.
    void eliminarPaquete(int trackingNumber); // Elimina un paquete por su número de seguimiento.
    void mostrarTabla() const; // Muestra el contenido de la tabla hash.
};

#endif // TABLAHASH_H