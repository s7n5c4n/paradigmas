#include "vehiculo.h"
#include <iostream>
#include <vector>

using namespace std;

class Moto : public Vehiculo{
public:
    Moto(string, int, int, bool, int);
    ~Moto() override;
    void mostrarAccesorios() override;
    void mostrarDetalles() override;
};
