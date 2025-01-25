//
// Created by Erik on 1/16/2025.
//

#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "Paquete.h" // Se incluye la definición de la clase Paquete.
#include <iostream> // Biblioteca estándar para la entrada y salida de datos.

// Clase que implementa una lista enlazada para gestionar paquetes.
class ListaEnlazada {
private:
    Paquete* head; // Puntero al primer elemento de la lista.

public:
    ListaEnlazada(); // Constructor que inicializa la lista.
    ~ListaEnlazada(); // Destructor que libera la memoria usada por los nodos.

    void addPackage(int id, const std::string& description); // Metodo para agregar un paquete al final de la lista.
    void showPackages() const; // Metodo para mostrar todos los paquetes en la lista.
};

#endif // LISTA_ENLAZADA_H