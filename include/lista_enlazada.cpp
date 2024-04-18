#include "lista_enlazada.h"

using namespace std;

// Constructor
ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

// Destructor
ListaEnlazada::~ListaEnlazada() {
    // Liberar la memoria de todos los nodos al destruir la lista
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Método para insertar un objeto Estudiante al inicio de la lista
void ListaEnlazada::insertarAlInicio(Vehiculo *vehiculo) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->datos = vehiculo;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// Vehiculo * ListaEnlazada::obtenerVehiculoTipoIndice(string _marca, string _tipo){
//     Nodo* actual = cabeza;
//     while (actual != nullptr) {
//         actual->datos->mostrarDetalles();
//         actual = actual->siguiente;
//         cout << endl;
//     }
// }

// Método para imprimir la lista
void ListaEnlazada::imprimirLista() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->datos->mostrarDetalles();
        actual = actual->siguiente;
        cout << endl;
    }
}
