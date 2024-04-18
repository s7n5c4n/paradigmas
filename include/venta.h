#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "vehiculo.h"

using namespace std;

class Venta{
private:
    int cantidadVehiculos;
    int cantidadAccesorios;
    int totalPrecioVehiculos;
    int totalDescuento;
    int totalGeneral;
    float descuento;

public:
    string rut;
    string nombre;
    string tipo; 
    Vehiculo* vehiculo;
    Venta(string, string , string, int, int, Vehiculo*);
    ~Venta();
    void guardarVenta();
    int obtenerCantidadVehiculosComprados();
    int obtenerTotalVenta();
    void generarVenta();
};

#endif
