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
    //Menu 3
    int obtenerPromedioVentaPorTipo(string);
    void imprimirPromedioVenta();
    //Menu 4
    int obtenerCantidadVehiculosCompradosPorTipo(string);
    void imprimirCantidadVehiculosComprados();
    //Menu 5
    void imprimirClientequeComproMasVehiculosPorTipo(string);
    void imprimirClientequeComproMasVehiculos();
    void imprimirClientequeComproMasAccesoriosPorTipo(string);
    void imprimirClientequeComproMasAccesorios();

    void imprimirLista() const;
};

#endif
