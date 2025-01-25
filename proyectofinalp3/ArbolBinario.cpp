//
// Created by Erik on 1/20/2025.
//

#include "ArbolBinario.h"

// Constructor que inicializa un árbol vacío.
ArbolBinario::ArbolBinario() : root(nullptr) {}

// Destructor que libera la memoria de todos los nodos del árbol.
ArbolBinario::~ArbolBinario() {
    eliminarArbol(root);
}

// Metodo público para insertar un cliente en el árbol.
void ArbolBinario::insertarCliente(int id, const std::string& name, bool balanceado) {
    if (balanceado) {
        root = insertarAVL(root, id, name); // Inserta en un árbol AVL.
    } else {
        root = insertarABB(root, id, name); // Inserta en un árbol ABB.
    }
}

// Metodo privado para insertar en un ABB.
Cliente* ArbolBinario::insertarABB(Cliente* node, int id, const std::string& name) {
    if (!node) { // Si el nodo es nulo, se crea uno nuevo.
        return new Cliente(id, name);
    }
    if (id < node->id) { // Si el ID es menor, se inserta en el subárbol izquierdo.
        node->left = insertarABB(node->left, id, name);
    } else if (id > node->id) { // Si el ID es mayor, se inserta en el subárbol derecho.
        node->right = insertarABB(node->right, id, name);
    }
    return node;
}

// Metodo privado para insertar en un AVL.
Cliente* ArbolBinario::insertarAVL(Cliente* node, int id, const std::string& name) {
    if (!node) { // Si el nodo es nulo, se crea uno nuevo.
        return new Cliente(id, name);
    }
    if (id < node->id) { // Si el ID es menor, se inserta en el subárbol izquierdo.
        node->left = insertarAVL(node->left, id, name);
    } else if (id > node->id) { // Si el ID es mayor, se inserta en el subárbol derecho.
        node->right = insertarAVL(node->right, id, name);
    }

    return balancear(node); // Balancea el árbol tras la inserción.
}

// Metodo privado para balancear un nodo en el árbol AVL.
Cliente* ArbolBinario::balancear(Cliente* node) {
    if (!node) return node;

    // Actualiza la altura del nodo.
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // Calcula el factor de balance.
    int balanceFactor = getBalanceFactor(node);

    // Caso de desbalanceo izquierda-izquierda.
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
        return rotacionDerecha(node);
    }

    // Caso de desbalanceo izquierda-derecha.
    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotacionIzquierda(node->left);
        return rotacionDerecha(node);
    }

    // Caso de desbalanceo derecha-derecha.
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
        return rotacionIzquierda(node);
    }

    // Caso de desbalanceo derecha-izquierda.
    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotacionDerecha(node->right);
        return rotacionIzquierda(node);
    }

    return node; // Nodo balanceado.
}

// Metodo privado para obtener la altura de un nodo.
int ArbolBinario::getHeight(Cliente* node) const {
    return node ? node->height : 0;
}

// Metodo privado para calcular el factor de balance de un nodo.
int ArbolBinario::getBalanceFactor(Cliente* node) const {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Rotación simple a la derecha.
Cliente* ArbolBinario::rotacionDerecha(Cliente* y) {
    Cliente* x = y->left;
    Cliente* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Actualiza las alturas.
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x; // Retorna la nueva raíz.
}

// Rotación simple a la izquierda.
Cliente* ArbolBinario::rotacionIzquierda(Cliente* x) {
    Cliente* y = x->right;
    Cliente* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Actualiza las alturas.
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y; // Retorna la nueva raíz.
}

// Metodo público para mostrar clientes usando un recorrido inorden.
void ArbolBinario::mostrarClientes() const {
    inOrder(root);
}

// Metodo privado para el recorrido inorden.
void ArbolBinario::inOrder(Cliente* node) const {
    if (node) { // Si el nodo no es nulo.
        inOrder(node->left); // Visita el subárbol izquierdo.
        std::cout << "ID: " << node->id << ", Name: " << node->name << std::endl;
        inOrder(node->right); // Visita el subárbol derecho.
    }
}

// Metodo público para liberar la memoria de todos los nodos del árbol.
void ArbolBinario::eliminarArbol(Cliente* node) {
    if (node) { // Si el nodo no es nulo.
        eliminarArbol(node->left); // Libera el subárbol izquierdo.
        eliminarArbol(node->right); // Libera el subárbol derecho.
        delete node; // Libera el nodo actual.
    }
}