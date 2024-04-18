#include "GestorVenta.h"
#include <iostream>

using namespace std;

GestorVenta::GestorVenta() : cabeza(nullptr) {}

GestorVenta::~GestorVenta() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual->datos; 
        delete actual; 
        actual = siguiente;
    }
}

void GestorVenta::insertarAlInicio(Venta* venta){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->datos = venta;
    nuevoNodo -> siguiente = cabeza;
    cabeza = nuevoNodo;
}

void GestorVenta::imprimirLista() const{
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->datos->guardarVenta();
        actual = actual->siguiente;
        cout << endl;
    }
}