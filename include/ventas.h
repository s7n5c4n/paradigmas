#ifndef VENTAS_H
#define VENTAS_H

#include <iostream>
#include <vector>
#include "vehiculo.h"

using namespace std;

class Venta {
protected:
    string rut;
    string nombre;
    int cantidadJuguetes;
    int cantidadAccesorios;
    Vehiculo* vehiculo;

    int totalPrecioAccesorios;
    int totalPrecioVehiculos;
    int totalDescuento;
    int totalGeneral;
    bool descuento;
public:
    Venta(string, string, int, int, Vehiculo*);
    ~Venta();
    void asignacionDescuento();
    void ventaCliente();
    int obtenerCantidadVehiculos();
    int obtenerPrecioTotalVehiculos();
    void obtenerTipoVehiculo();
    void guardarDetalleVenta();
};
#endif