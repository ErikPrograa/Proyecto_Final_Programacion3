//
// Created by Erik on 1/16/2025.
//

#ifndef COLA_H
#define COLA_H

#include "Paquete.h"
#include <iostream>

// Clase que implementa una cola para manejar paquetes (estructura FIFO).
class Cola {
private:
    Paquete* front; // Puntero al primer elemento de la cola (inicio).
    Paquete* rear; // Puntero al último elemento de la cola (final).

public:
    Cola(); // Constructor que inicializa una cola vacía.
    ~Cola(); // Destructor que libera la memoria de todos los elementos en la cola.

    void loadPackage(int id, const std::string& description); // Metodo para agregar un paquete a la cola.
    void deliverPackage(); // Metodo para retirar (entregar) un paquete de la cola.
    void showQueue() const; // Metodo para mostrar todos los paquetes en la cola.
};

#endif // COLA_H