//
// Created by Erik on 1/16/2025.
//

#include "Pila.h"

// Constructor de la clase Pila. Inicializa el puntero top como nullptr (pila vacía).
Pila::Pila() : top(nullptr) {}

// Destructor de la clase Pila. Libera la memoria de todos los elementos en la pila.
Pila::~Pila() {
    while (top) { // Mientras haya elementos en la pila.
        Paquete* temp = top; // Guarda el nodo actual en un puntero temporal.
        top = top->next; // Avanza al siguiente nodo.
        delete temp; // Libera la memoria del nodo actual.
    }
}

// Metodo para agregar un paquete a la cima de la pila.
void Pila::pushPackage(int id, const std::string& description) {
    // Crea un nuevo paquete con los datos proporcionados.
    Paquete* newPackage = new Paquete(id, description);
    newPackage->next = top; // El nuevo nodo apunta al nodo que estaba en la cima.
    top = newPackage; // Actualiza el puntero top al nuevo nodo.
    std::cout << "Paquete devuelto: " << description << std::endl;
}

// Metodo para retirar (procesar) un paquete de la cima de la pila.
void Pila::popPackage() {
    if (!top) { // Si la pila está vacía da el siguiente mensaje.
        std::cout << "No hay paquetes devueltos para procesar." << std::endl;
        return;
    }
    Paquete* temp = top; // Guarda el nodo actual en un puntero temporal.
    top = top->next; // Avanza al siguiente nodo en la pila.
    std::cout << "Procesando paquete devuelto: " << temp->description << std::endl; // Mensaje de confirmación.
    delete temp; // Libera la memoria del nodo procesado.
}

// Metodo para mostrar todos los paquetes en la pila.
void Pila::showStack() const {
    Paquete* temp = top; // Comienza desde la cima de la pila.
    std::cout << "Paquetes devueltos:" << std::endl;
    while (temp) { // Recorre todos los nodos de la pila.
        // Imprime la información del paquete actual.
        std::cout << "ID: " << temp->id << ", Descripcion: " << temp->description << std::endl;
        temp = temp->next; // Avanza al siguiente nodo.
    }
}