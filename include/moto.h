#include "vehiculo.h"
#include <iostream>

using namespace std;

class Moto : public Vehiculo{
public:
    Moto(string, int, int, int);
    ~Moto() override;
    void mostrarDetalles() override;
};
