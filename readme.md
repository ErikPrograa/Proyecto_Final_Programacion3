# Documentación del Proyecto: Sistema de Gestión de Rutas y Logística

## Descripción General
Este proyecto es un sistema de gestión de rutas y logística desarrollado en C++ para una empresa de mensajería. Utiliza diversas estructuras de datos y algoritmos para resolver problemas relacionados con la planificación de rutas, almacenamiento de paquetes y optimización de entregas.

---

## Funcionalidades Principales

### 1. **Gestión de Recepción de Paquetes**
- Implementado mediante una **lista enlazada**.
- Permite registrar y almacenar paquetes en la bodega.

### 2. **Carga y Entrega de Paquetes**
- Simulado mediante una **cola (FIFO)**.
- Carga los paquetes en el vehículo y los entrega en el orden de llegada.

### 3. **Gestión de Paquetes Devueltos**
- Implementado mediante una **pila (LIFO)**.
- Administra los paquetes que deben ser devueltos por errores de entrega.

### 4. **Base de Datos de Clientes**
- Implementada con un **árbol binario de búsqueda (ABB)**.
- Transformado en un **árbol AVL** para garantizar balance y optimizar búsquedas.

### 5. **Ordenamiento de Paquetes**
- Dos algoritmos implementados:
  - **QuickSort**: Ordenamiento rápido para grandes conjuntos de datos.
  - **MergeSort**: Divide y conquista para estabilidad y eficiencia.

### 6. **Seguimiento de Paquetes**
- Utiliza una **tabla hash** para acceso rápido a la información de seguimiento de los paquetes.

### 7. **Optimización de Rutas**
- **Grafos ponderados** representan la red de distribución de rutas.
- Algoritmo de **Dijkstra** para calcular la ruta más corta desde el centro de distribución a los destinos.

---

## Estructuras de Datos y Algoritmos

### Lista de Clases Principales

1. **`Paquete`**
   - Representa un paquete con ID, descripción, estado y puntero al siguiente paquete.

2. **`ListaEnlazada`**
   - Administra la recepción de paquetes.

3. **`Cola`**
   - Simula la carga y entrega de paquetes.

4. **`Pila`**
   - Gestiona los paquetes devueltos.

5. **`Cliente`**
   - Representa un cliente con ID, nombre y punteros para integración en un árbol.

6. **`ArbolBinario`**
   - Maneja los datos de clientes en un ABB y permite la conversión a AVL.

7. **`Ordenamiento`**
   - Contiene implementaciones de QuickSort y MergeSort para ordenar paquetes.

8. **`TablaHash`**
   - Permite almacenar y buscar información de seguimiento de paquetes de manera eficiente.

9. **`Grafo`**
   - Modela las rutas de distribución con una matriz de adyacencia.

10. **`Dijkstra`**
    - Implementa el algoritmo para calcular rutas más cortas en el grafo.

---

## Estructura del Proyecto

```
├── Cliente.cpp/h            # Gestión de clientes
├── Cola.cpp/h               # Gestión de carga y entrega de paquetes
├── Dijkstra.cpp/h           # Algoritmo de rutas más cortas
├── Grafo.cpp/h              # Modelado de la red de distribución
├── ListaEnlazada.cpp/h      # Gestión de paquetes en bodega
├── Ordenamiento.cpp/h       # Algoritmos de ordenamiento
├── Paquete.cpp/h            # Representación de paquetes
├── Pila.cpp/h               # Gestión de paquetes devueltos
├── TablaHash.cpp/h          # Información de seguimiento de paquetes
```



---

## Créditos
Proyecto desarrollado por Erik en enero de 2025.




