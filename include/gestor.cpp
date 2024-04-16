#include "gestor.h"
#include "ventas.h"
#include <iostream>

using namespace std;

void GestorVentas::agregarVenta(Venta* venta) {
    ventas.push_back(venta);
}

void GestorVentas::mostrarTotalVehiculosComprados() {
    int totalAutos = 0, totalMotos = 0, totalCamiones = 0, totalGeneral = 0;
    for (Venta* venta : ventas) {
        if (dynamic_cast<Auto*>(venta)) {
            totalAutos += venta->obtenerCantidadVehiculos();
        } else if (dynamic_cast<Moto*>(venta)) {
            totalMotos += venta->obtenerCantidadVehiculos();
        } else if (dynamic_cast<Camion*>(venta)) {
            totalCamiones += venta->obtenerCantidadVehiculos();
        }
        totalGeneral += venta->obtenerCantidadVehiculos();
    }
    cout << "Total de autos vendidos: " << totalAutos << endl;
    cout << "Total de motos vendidas: " << totalMotos << endl;
    cout << "Total de camiones vendidos: " << totalCamiones << endl;
    cout << "Total general de vehículos vendidos: " << totalGeneral << endl;
}
