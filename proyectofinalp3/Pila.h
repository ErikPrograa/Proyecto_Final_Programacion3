//
// Created by Erik on 1/16/2025.
//

#ifndef PILA_H
#define PILA_H

#include "Paquete.h"
#include <iostream>

// Clase que implementa una pila para manejar paquetes (estructura LIFO).
class Pila {
private:
    Paquete* top; // Puntero al elemento en la cima de la pila.

public:
    Pila(); // Constructor que inicializa una pila vacía.
    ~Pila(); // Destructor que libera la memoria de todos los elementos en la pila.

    void pushPackage(int id, const std::string& description); // Metodo para agregar un paquete a la pila.
    void popPackage(); // Metodo para retirar (procesar) un paquete de la cima de la pila.
    void showStack() const; // Metodo para mostrar todos los paquetes en la pila.
};

#endif // PILA_H