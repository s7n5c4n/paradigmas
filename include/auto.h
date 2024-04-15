#include "Vehiculo.h"

using namespace std;

class Auto : public Vehiculo {
public:
    Auto(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio);
    void agregarAccesorios() override;
    void mostrarDetalles() const override;
};
