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

int GestorVenta::obtenerCantidadVehiculosCompradosPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerCantidadArticulos();
        }
        actual = actual->siguiente;
    }

    return totalVehiculosComprado;
}

void GestorVenta::imprimirCantidadVehiculosComprados(){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0;

    while (actual != nullptr) {
        totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerCantidadArticulos();
        actual = actual->siguiente;
    }

    cout<< "La cantidad de vehiculos vendida es: " << totalVehiculosComprado << endl;
}

int GestorVenta::obtenerPromedioVentaPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0; 
    int i = 0;
    int promedio = 0;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerTotalVenta();
        }
        actual = actual->siguiente;
        i++;
    }

    return promedio = totalVehiculosComprado / i;
}

void GestorVenta::imprimirPromedioVenta(){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0; 
    int i = 0;
    int promedio = 0;

    while (actual != nullptr) {
        totalVehiculosComprado = totalVehiculosComprado + actual->datos-> obtenerTotalVenta();
        actual = actual->siguiente;
        i++;
    }
    promedio = totalVehiculosComprado / i;
    cout << "El promedio de ventas de todos los vehiculos es: " << promedio << endl;
}

void GestorVenta::imprimirClientequeComproMasVehiculosPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0; 
    int promedio = 0;
    string cliente;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            if (actual->datos->obtenerCantidadArticulos() > totalVehiculosComprado){
                totalVehiculosComprado = actual->datos->obtenerCantidadArticulos();
                cliente = actual->datos->nombre;
            }
        }
        actual = actual->siguiente;
    }

    if (cliente == ""){
        cout << "No hay clientes que hayan comprado vehiculos de tipo "<< tipo << endl;
    }
    else{
        cout << "El cliente que compro mas vehiculos de tipo "<< tipo << "es" << cliente << endl;
    }
}

void GestorVenta::imprimirClientequeComproMasVehiculos(){
    Nodo* actual = cabeza;
    int totalVehiculosComprado = 0; 
    int promedio = 0;
    string cliente;

    while (actual != nullptr) {
        if (actual->datos->obtenerCantidadArticulos() > totalVehiculosComprado){
            totalVehiculosComprado = actual->datos->obtenerCantidadArticulos();
            cliente = actual->datos->nombre;
        }
        actual = actual->siguiente;
    }
    if (cliente == ""){
        cout << "No hay clientes que hayan comprado vehiculos" << endl;
    }
    else{
        cout << "El cliente que compro mas vehiculos es: " << cliente << endl;
    }
}

void GestorVenta::imprimirClientequeComproMasAccesoriosPorTipo(string tipo){
    Nodo* actual = cabeza;
    int totalAccesoriosComprado = 0;
    int promedio = 0;
    string cliente;

    while (actual != nullptr) {
        if (actual->datos->obtenerTipoArticulo() == tipo){
            if (actual->datos->obtenerCantidadArticulos() > totalAccesoriosComprado){
                totalAccesoriosComprado = actual->datos->obtenerCantidadArticulos();
                cliente = actual->datos->nombre;
            }
        }
        actual = actual->siguiente;
    }

    if (cliente == ""){
        cout << "No hay clientes que hayan comprado accesorios de tipo "<< tipo << endl;
    }
    else{
        cout << "El cliente que compro mas accesorios de tipo "<< tipo << "es" << cliente << endl;
    }
}

void GestorVenta::imprimirClientequeComproMasAccesorios(){
    Nodo* actual = cabeza;
    int totalAccesoriosComprado = 0;
    int promedio = 0;
    string cliente;

    while (actual != nullptr) {
        if (actual->datos->obtenerCantidadArticulos() > totalAccesoriosComprado){
            totalAccesoriosComprado = actual->datos->obtenerCantidadArticulos();
            cliente = actual->datos->nombre;
        }
        actual = actual->siguiente;
    }
    if (cliente == ""){
        cout << "No hay clientes que hayan comprado accesorios" << endl;
    }
    else{
        cout << "El cliente que compro mas accesorios es: " << cliente << endl;
    }
}

