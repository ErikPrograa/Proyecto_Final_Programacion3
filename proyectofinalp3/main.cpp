#include <iostream> // Biblioteca estándar para entrada y salida de datos.
#include "ListaEnlazada.h" // Gestión de paquetes en bodega.
#include "Cola.h" // Gestión de carga y entrega de paquetes.
#include "Pila.h" // Gestión de paquetes devueltos.
#include "TablaHash.h" // Seguimiento de paquetes.
#include "Grafo.h" // Modelado de la red de distribución.
#include "Dijkstra.h" // Algoritmo para rutas más cortas.
#include "ArbolBinario.h" // Gestión de clientes en un árbol binario.
#include "Ordenamiento.h" // Algoritmos de ordenamiento de paquetes.

int main() {
    // Prueba de ListaEnlazada.
    std::cout << "Testing Linked List (ListaEnlazada):" << std::endl;
    ListaEnlazada warehouse; // Crea una lista enlazada para almacenar paquetes.
    warehouse.addPackage(1, "Package 1"); // Agrega el paquete 1.
    warehouse.addPackage(2, "Package 2"); // Agrega el paquete 2.
    warehouse.addPackage(3, "Package 3"); // Agrega el paquete 3.
    warehouse.showPackages(); // Muestra todos los paquetes.
    std::cout << std::endl;

    // Prueba de Cola.
    std::cout << "Testing Queue (Cola):" << std::endl;
    Cola deliveryQueue; // Crea una cola para simular la carga de paquetes.
    deliveryQueue.loadPackage(4, "Package 4"); // Carga el paquete 4.
    deliveryQueue.loadPackage(5, "Package 5"); // Carga el paquete 5.
    deliveryQueue.showQueue(); // Muestra los paquetes en la cola.
    deliveryQueue.deliverPackage(); // Entrega el primer paquete.
    deliveryQueue.showQueue(); // Muestra los paquetes restantes.
    std::cout << std::endl;

    // Prueba de Pila.
    std::cout << "Testing Stack (Pila):" << std::endl;
    Pila returnStack; // Crea una pila para gestionar paquetes devueltos.
    returnStack.pushPackage(6, "Returned Package 6"); // Agrega el paquete devuelto 6.
    returnStack.pushPackage(7, "Returned Package 7"); // Agrega el paquete devuelto 7.
    returnStack.showStack(); // Muestra los paquetes devueltos.
    returnStack.popPackage(); // Procesa el paquete en la cima de la pila.
    returnStack.showStack(); // Muestra los paquetes restantes.
    std::cout << std::endl;

    // Prueba de TablaHash.
    std::cout << "Testing Hash Table (TablaHash):" << std::endl;
    TablaHash hashTable(10); // Crea una tabla hash con tamaño 10.
    hashTable.insertarPaquete({101, "Electronics", "In Transit"}); // Inserta un paquete.
    hashTable.insertarPaquete({102, "Books", "Delivered"}); // Inserta otro paquete.
    hashTable.mostrarTabla(); // Muestra la tabla hash.
    auto found = hashTable.buscarPaquete(101); // Busca el paquete con ID 101.
    if (found) { // Si se encuentra el paquete.
        std::cout << "Found Package: " << found->description << ", Status: " << found->status << std::endl;
    }
    hashTable.eliminarPaquete(101); // Elimina el paquete con ID 101.
    hashTable.mostrarTabla(); // Muestra la tabla hash actualizada.
    std::cout << std::endl;

    // Prueba de ArbolBinario.
    std::cout << "Testing Binary Tree (ArbolBinario):" << std::endl;
    ArbolBinario clientTree; // Crea un árbol binario para gestionar clientes.
    clientTree.insertarCliente(1, "Client A"); // Inserta el cliente A.
    clientTree.insertarCliente(3, "Client C"); // Inserta el cliente C.
    clientTree.insertarCliente(2, "Client B"); // Inserta el cliente B.
    clientTree.mostrarClientes(); // Muestra todos los clientes en el árbol.
    std::cout << std::endl;

    // Prueba de Grafo y Dijkstra.
    std::cout << "Testing Graph (Grafo) and Dijkstra Algorithm:" << std::endl;
    Grafo graph(5); // Crea un grafo con 5 vértices.
    graph.agregarArista(0, 1, 10); // Agrega una arista con peso 10.
    graph.agregarArista(0, 2, 20); // Agrega otra arista.
    graph.agregarArista(1, 3, 15); // Agrega otra arista.
    graph.agregarArista(2, 3, 30); // Agrega otra arista.
    graph.mostrarGrafo(); // Muestra la matriz de adyacencia.

    // Calcula las distancias más cortas desde el nodo 0.
    auto distances = Dijkstra::rutaMasCorta(graph.getAdjMatrix(), 0);
    std::cout << "Shortest distances from node 0: ";
    for (int d : distances) {
        if (d == std::numeric_limits<int>::max()) { // Si la distancia es infinita.
            std::cout << "INF ";
        } else {
            std::cout << d << " "; // Muestra la distancia.
        }
    }
    std::cout << std::endl;

    // Prueba de algoritmos de ordenamiento.
    std::cout << "Testing Sorting Algorithms (Ordenamiento):" << std::endl;
    std::vector<PaqueteOrdenado> packages = {
        {1, 5, "Package A"}, // Paquete A.
        {2, 3, "Package B"}, // Paquete B.
        {3, 8, "Package C"}, // Paquete C.
        {4, 1, "Package D"}, // Paquete D.
        {5, 7, "Package E"}  // Paquete E.
    };

    // Muestra la lista original de paquetes.
    std::cout << "Original packages list:" << std::endl;
    for (const auto& pkg : packages) {
        std::cout << "[ID: " << pkg.id << ", Priority: " << pkg.priority << ", Description: "
                  << pkg.description << "]" << std::endl;
    }

    // Ordena usando QuickSort.
    std::cout << "\nQuickSort by priority:" << std::endl;
    Ordenamiento::quickSort(packages, 0, packages.size() - 1);
    for (const auto& pkg : packages) {
        std::cout << "[ID: " << pkg.id << ", Priority: " << pkg.priority << ", Description: "
                  << pkg.description << "]" << std::endl;
    }

    // Ordena usando MergeSort.
    std::cout << "\nMergeSort by priority:" << std::endl;
    Ordenamiento::mergeSort(packages, 0, packages.size() - 1);
    for (const auto& pkg : packages) {
        std::cout << "[ID: " << pkg.id << ", Priority: " << pkg.priority << ", Description: "
                  << pkg.description << "]" << std::endl;
    }

    return 0;
}