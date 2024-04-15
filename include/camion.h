#include "vehiculo.h"
#include <iostream>
#include <vector>

using namespace std;

class Camion : public Vehiculo{
public:
    Camion(string, int, int, bool, int);
    ~Camion() override;
    void mostrarAccesorios() override;
    void mostrarDetalles() override;
};