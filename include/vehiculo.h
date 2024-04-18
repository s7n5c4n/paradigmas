#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>

using namespace std;

class Vehiculo{
protected:
    int cantidadRuedas;
    bool controlRemoto;
    int yearFabricacion;

public:
    string marca;
    int precio;

    Vehiculo(string, int, int, int);
    virtual ~Vehiculo();
    virtual void mostrarDetalles();
};

#endif
