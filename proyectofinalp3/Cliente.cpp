//
// Created by Erik on 1/20/2025.
//

#include "Cliente.h"

// Constructor de la clase Cliente. Inicializa los atributos del cliente.
Cliente::Cliente(int _id, const std::string& _name)
    : id(_id), // Inicializa el atributo id con el valor proporcionado.
      name(_name), // Inicializa el atributo name con el valor proporcionado.
      left(nullptr), // Inicializa el puntero left como nullptr, indicando que no tiene hijo izquierdo.
      right(nullptr), // Inicializa el puntero right como nullptr, indicando que no tiene hijo derecho.
      height(1) // Inicializa la altura del nodo como 1, útil para árboles AVL.
{}