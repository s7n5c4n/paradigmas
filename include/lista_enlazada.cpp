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

Vehiculo* ListaEnlazada::obtenerVehiculoIndice(int indice){
    Nodo *actual = cabeza;
    int i = 1;

    Vehiculo* vehiculo = nullptr;

    while(actual != nullptr){
        if(i == indice){
            vehiculo = actual->datos;
            break;
        }
        actual = actual->siguiente;
        i++;
    }

    return vehiculo;
}

// Método para imprimir la lista
void ListaEnlazada::imprimirLista() const {
    Nodo* actual = cabeza;
    int i = 1;
    while (actual != nullptr) {
        cout << i << ". ";
        cout << actual->datos->marca << ": " << actual->datos->precio << endl;
        actual = actual->siguiente;
        i++;
    }
}
