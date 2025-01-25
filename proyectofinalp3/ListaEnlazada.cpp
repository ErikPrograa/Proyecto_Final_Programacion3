//
// Created by Erik on 1/16/2025.
//

#include "ListaEnlazada.h"

// Constructor de la lista enlazada.
ListaEnlazada::ListaEnlazada() : head(nullptr) {}

// Destructor de la lista enlazada.
ListaEnlazada::~ListaEnlazada() {
    Paquete* current = head; // Empieza desde la cabeza de la lista.
    while (current) { // Recorre la lista hasta que no haya más nodos.
        Paquete* temp = current; // Guarda un puntero temporal al nodo actual.
        current = current->next; // Avanza al siguiente nodo.
        delete temp; // Libera la memoria del nodo actual.
    }
}

// Metodo para agregar un paquete al final de la lista.
void ListaEnlazada::addPackage(int id, const std::string& description) {
    // Crea un nuevo paquete con los datos proporcionados.
    Paquete* newPackage = new Paquete(id, description);
    if (!head) { // Si la lista está vacía.
        head = newPackage; // El nuevo paquete se convierte en la cabeza de la lista.
    } else { // Si la lista no está vacía.
        Paquete* temp = head; // Empieza desde la cabeza.
        while (temp->next) { // Recorre la lista hasta el último nodo.
            temp = temp->next;
        }
        temp->next = newPackage; // Añade el nuevo paquete al final de la lista.
    }
    std::cout << "Paquete cargado: " << description << std::endl;
}

// Metodo para mostrar todos los paquetes almacenados en la lista.
void ListaEnlazada::showPackages() const {
    Paquete* temp = head; // Comienza desde la cabeza de la lista.
    std::cout << "Paquetes en almacenamiento:" << std::endl;
    while (temp) { // Recorre la lista hasta el final.
        std::cout << "ID: " << temp->id << ", Descripcion: " << temp->description << std::endl;
        temp = temp->next; // Avanza al siguiente nodo.
    }
}