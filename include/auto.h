#include "vehiculo.h"
#include <iostream>
#include <vector>

using namespace std;

class Auto : public Vehiculo{
public:
    Auto(string, int, int, bool, int);
    ~Auto() override;
    void mostrarAccesorios() override;
    void mostrarDetalles() override;
};
