#ifndef VENTA_H
#define VENTA_H

#include <iostream>

using namespace std;

class Venta{
public:
    string rut;
    string nombre;
    string tipo;
    Venta(string, string, string);
    ~Venta();
    virtual int obtenerCantidadArticulos() = 0;
    virtual int obtenerTotalVenta() = 0;
    virtual string obtenerTipoArticulo() = 0;
    virtual void mostrarVenta();
    virtual void generarVenta();
};

#endif
