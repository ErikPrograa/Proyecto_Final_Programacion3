//
// Created by Erik on 1/20/2025.
//

#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "Cliente.h"
#include <iostream>

// Clase que implementa un árbol binario para gestionar clientes.
class ArbolBinario {
private:
    Cliente* root; // Puntero a la raíz del árbol.

    // Metodos privados para manejo interno del árbol.
    Cliente* insertarABB(Cliente* node, int id, const std::string& name); // Inserción en un árbol binario de búsqueda (ABB).
    void inOrder(Cliente* node) const; // Recorrido en orden para mostrar clientes.

    Cliente* insertarAVL(Cliente* node, int id, const std::string& name); // Inserción en un árbol AVL.
    Cliente* balancear(Cliente* node); // Balancea el árbol AVL después de una inserción.
    int getHeight(Cliente* node) const; // Obtiene la altura de un nodo.
    int getBalanceFactor(Cliente* node) const; // Calcula el factor de balance de un nodo.
    Cliente* rotacionDerecha(Cliente* y); // Rotación simple a la derecha.
    Cliente* rotacionIzquierda(Cliente* x); // Rotación simple a la izquierda.

public:
    ArbolBinario(); // Constructor que inicializa un árbol vacío.
    ~ArbolBinario(); // Destructor que libera todos los nodos del árbol.

    void insertarCliente(int id, const std::string& name, bool balanceado = false); // Inserta un cliente, permite escoger entre ABB y AVL.
    void mostrarClientes() const; // Muestra todos los clientes usando un recorrido inorden.
    void convertirEnAVL(); // Convierte un árbol ABB en un AVL (a implementar).
    void eliminarArbol(Cliente* node); // Libera la memoria de todos los nodos de un árbol.
};

#endif // ARBOL_BINARIO_H