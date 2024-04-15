#include "Vehiculo.h"

using namespace std;

class Camion : public Vehiculo {
public:
    Camion(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio);
    void agregarAccesorios() override;
    void mostrarDetalles() const override;
};