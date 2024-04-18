#ifndef GESTOR_VENTA_H
#define GESTOR_VENTA_H
#include "venta.h"

class GestorVenta {
private:
    struct Nodo {
        Venta* datos;
        Nodo* siguiente;
    };
    Nodo* cabeza; 
public:
    GestorVenta();
    ~GestorVenta();

    void insertarAlInicio(Venta*);
    // Método para imprimir la lista
    void imprimirLista() const;

    void GestorVenta::VenderVehiculo(const string& nombreCliente, const string& rutCliente) {

        cout << "Vehículo vendido al cliente " << nombreCliente << " (RUT: " << rutCliente << ")" << endl;

    };

    void GestorVenta::VenderAccesorio(const string& nombreCliente, const string& rutCliente){

        cout << "Accesorio vendido al cliente " << nombreCliente << " (RUT: " << rutCliente << ")" << endl;
    };
}
#endif
