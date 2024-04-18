#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "vehiculo.h"

// Definición de la clase ListaEnlazada
class ListaEnlazada {
private:
    struct Nodo {
        Vehiculo *datos;
        Nodo* siguiente;
    };
    Nodo* cabeza; // Puntero al primer nodo de la lista
public:
    // Constructor
    ListaEnlazada();

    // Destructor
    ~ListaEnlazada();

    // Método para insertar un objeto Vehiculo al inicio de la lista
    void insertarAlInicio(Vehiculo *vehiculo);

    //Vehiculo * obtenerVehiculoTipoIndice(string, string);

    // Método para imprimir la lista
    void imprimirLista() const;
};

#endif