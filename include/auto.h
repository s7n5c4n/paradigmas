#include "vehiculo.h"
#include <iostream>

using namespace std;

class Auto : public Vehiculo{
public:
    Auto(string, int, int, int);
    ~Auto() override;
    void mostrarDetalles() override;
};
