#include "Vehiculo.h"

using namespace std;

class Moto : public Vehiculo {
public:
    Moto(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio);
    void agregarAccesorios() override;
    void mostrarDetalles() const override;
};