//
// Created by Erik on 1/16/2025.
//

#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

// Clase que representa un paquete.
class Paquete {
public:
    int id; // Identificador único del paquete.
    std::string description; // Descripción del contenido del paquete.
    std::string status; // Estado actual del paquete.
    Paquete* next; // Puntero al siguiente paquete.

    // Constructor de la clase que inicializa los atributos con los valores dados.
    Paquete(int _id, const std::string& _description, const std::string& _status = "");
};

#endif // PAQUETE_H