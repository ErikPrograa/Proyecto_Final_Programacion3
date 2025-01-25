//
// Created by Erik on 1/16/2025.
//

#include "Cola.h"

// Constructor de la clase Cola. Inicializa los punteros front y rear como nullptr (cola vacía).
Cola::Cola() : front(nullptr), rear(nullptr) {}

// Destructor de la clase Cola. Libera la memoria de todos los elementos en la cola.
Cola::~Cola() {
    while (front) { // Mientras haya elementos en la cola.
        Paquete* temp = front; // Guarda el nodo actual en un puntero temporal.
        front = front->next; // Avanza al siguiente nodo.
        delete temp; // Libera la memoria del nodo actual.
    }
}

// Metodo para cargar un paquete en la cola.
void Cola::loadPackage(int id, const std::string& description) {
    // Crea un nuevo paquete con los datos proporcionados.
    Paquete* newPackage = new Paquete(id, description);
    if (!rear) { // Si la cola está vacía.
        front = rear = newPackage; // El nuevo paquete se convierte en el primer y último nodo.
    } else { // Si la cola no está vacía.
        rear->next = newPackage; // El último nodo apunta al nuevo paquete.
        rear = newPackage; // Actualiza el puntero rear al nuevo último nodo.
    }
    std::cout << "Paquete cargado en vehiculo: " << description << std::endl;
}

// Método para entregar (retirar) un paquete de la cola.
void Cola::deliverPackage() {
    if (!front) { // Si la cola está vacía imprime lo siguiente.
        std::cout << "No hay paquetes cargados en vehiculo." << std::endl;
        return;
    }
    Paquete* temp = front; // Guarda el primer nodo en un puntero temporal.
    front = front->next; // Avanza al siguiente nodo de la cola.
    std::cout << "Paquete entregado: " << temp->description << std::endl;
    delete temp; // Libera la memoria del nodo entregado.
    if (!front) { // Si la cola queda vacía después de la entrega.
        rear = nullptr; // Actualiza el puntero rear a nullptr.
    }
}

// Metodo para mostrar todos los paquetes en la cola.
void Cola::showQueue() const {
    Paquete* temp = front; // Comienza desde el primer nodo de la cola.
    std::cout << "Paquetes cargados en vehiculo:" << std::endl;
    while (temp) { // Recorre todos los nodos de la cola.
        // Imprime la información del paquete actual.
        std::cout << "ID: " << temp->id << ", Descripcion: " << temp->description << std::endl;
        temp = temp->next; // Avanza al siguiente nodo.
    }
}