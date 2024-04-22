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
    void obtenerTotalVehiculosCompradosPorTipo(string);
    void obtenerPromedioVentaPorTipo(string);
    void imprimirLista() const;
};

#endif
