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
        cout << actual -> datos-> obtenerTipoArticulo() << endl;
        actual = actual->siguiente;
        cout << endl;
    }
}

void GestorVenta::obtenerTotalVehiculosCompradosPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalVehiculosComprado;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerCantidadArticulos();
        }
        actual = actual->siguiente;
        cout << endl;
    }

    cout<< "El total de "<< tipo << "vendidos es $" << totalVehiculosComprado << endl;
}

void GestorVenta::obtenerPromedioVentaPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalVehiculosComprado;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerCantidadArticulos();
        }
        actual = actual->siguiente;
        cout << endl;
    }

    cout<< "El total de "<< tipo << "vendidos es $" << totalVehiculosComprado << endl;
}

