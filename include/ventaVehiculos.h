#ifndef VENTA_VEHICULOS
#define VENTA_VEHICULOS
#include <iostream>
#include <vector>
#include "venta.h"
#include "accesorio.h"
#include "vehiculo.h"
#include "ventaAccesorios.h"

using namespace std;

class VentaVehiculo : public Venta{
private:
    int cantidadVehiculos = 0;
    int cantidadAccesorios = 0;
    int totalPrecioAccesorios = 0;
    int totalPrecioVehiculos;
    int totalDescuento;
    int totalGeneral;
    float descuento;

public:
    vector<Accesorio> & accesoriosIniciales;
    Vehiculo* vehiculo;
    VentaVehiculo(string, string , string, int, Vehiculo*, vector<Accesorio> &);
    ~VentaVehiculo();
    void mostrarVenta() override;
    int obtenerCantidadArticulos() override;
    int obtenerTotalVenta() override;
    string obtenerTipoArticulo() override;
    void generarVenta() override;
    void agregarVenta();
};

#endif