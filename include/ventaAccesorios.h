#include "venta.h"
#include "accesorio.h"
#include <iostream>
#include <vector>

using namespace std;

class VentaAccesorios : public Venta{
private:
    int totalPrecioAccesorios;

public:
    vector<Accesorio> & accesoriosIniciales;
    int cantidad;
    VentaAccesorios(string, string, string, vector<Accesorio> &);
    ~VentaAccesorios();
    int obtenerCantidadArticulos() override;
    int obtenerTotalVenta() override;
    string obtenerTipoArticulo() override;
    void mostrarVenta() override;
    void generarVenta() override;
};
