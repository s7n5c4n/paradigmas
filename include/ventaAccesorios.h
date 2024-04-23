#ifndef VENTAACCESORIOS_H
#define VENTAACCESORIOS_H
#include "venta.h"
#include "accesorio.h"
#include <iostream>
#include <vector>

using namespace std;

class VentaAccesorios : public Venta{
private:
    int totalPrecioAccesorios = 0;
    int cantidad;
public:
    struct AccesorioCantidad {
        Accesorio accesorio;
        int cantidad;
        
        AccesorioCantidad(const Accesorio& _accesorio, int _cantidad) : accesorio(_accesorio), cantidad(_cantidad) {}
    };
    vector<Accesorio> & accesoriosIniciales;
    vector<AccesorioCantidad> accesorios;
    VentaAccesorios(string, string, string, vector<Accesorio> &);
    ~VentaAccesorios();
    int obtenerCantidadArticulos() override;
    int obtenerTotalVenta() override;
    void agregarAccesorio(Accesorio, int);
    bool buscarAccesorio(vector<Accesorio> &, vector<AccesorioCantidad> &, int);
    string obtenerTipoArticulo() override;
    void mostrarVenta() override;
    void generarVenta() override;
};

#endif