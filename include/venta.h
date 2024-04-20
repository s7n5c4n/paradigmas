#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "vehiculo.h"

using namespace std;

class Venta{
public:
    string rut;
    string nombre;
    Venta(string, string);
    ~Venta();
    virtual void generarVenta();
};

#endif
