#ifndef VENTA_VEHICULOS
#define VENTA_VEHICULOS
#include <iostream>
#include <vector>
#include "venta.h"
#include "accesorio.h"
#include "vehiculo.h"

using namespace std;

class VentaVehiculo : public Venta{
private:
    int cantidadVehiculos;
    int cantidadAccesorios;
    int totalPrecioVehiculos;
    int totalDescuento;
    int totalGeneral;
    float descuento;

public:
    Vehiculo* vehiculo;
    VentaVehiculo(string, string , string, int, int, Vehiculo*);
    ~VentaVehiculo();
    void mostrarVenta() override;
    int obtenerCantidadArticulos() override;
    int obtenerTotalVenta() override;
    string obtenerTipoArticulo() override;
    void generarVenta() override;
    void agregarVenta();
};

#endif