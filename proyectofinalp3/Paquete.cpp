//
// Created by Erik on 1/16/2025.
//

#include "Paquete.h" // Inclusión del archivo de cabecera de la clase.

// Implementación del constructor de la clase Paquete.
Paquete::Paquete(int _id, const std::string& _description, const std::string& _status)
    : id(_id), // Inicializa el atributo id con el valor _id.
      description(_description), // Inicializa el atributo description con el valor _description.
      status(_status), // Inicializa el atributo status con el valor _status.
      next(nullptr) // Inicializa el puntero next con nullptr, ya que no apunta a otro paquete al crearse.
{}