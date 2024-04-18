#include "vehiculo.h"
#include <iostream>

using namespace std;

class Camion : public Vehiculo{
public:
    Camion(string, int, int, int);
    ~Camion() override;
    void mostrarDetalles() override;
};