//
// Created by Erik on 1/20/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

// Clase que representa un cliente en el sistema.
class Cliente {
public:
    int id; // Identificador único del cliente.
    std::string name; // Nombre del cliente.
    Cliente* left; // Puntero al nodo izquierdo en un árbol binario.
    Cliente* right; // Puntero al nodo derecho en un árbol binario.
    int height; // Altura del nodo, utilizada en árboles AVL.

    // Constructor que inicializa los atributos del cliente.
    Cliente(int _id, const std::string& _name);
};

#endif // CLIENTE_H
