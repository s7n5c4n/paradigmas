#ifndef GESTOR_H
#define GESTOR_H
#include "ventas.h"
#include <iostream>

class GestorVentas {
private:
    vector<Venta*> ventas;
public:
    void agregarVenta(Venta*);

    void mostrarTotalVehiculosComprados();
};

#endif
