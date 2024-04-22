#include <iostream>
#include "venta.h"
#include <fstream>

using namespace std;

Venta::Venta(string _rut, string _nombre, string _tipo){
    rut = _rut;
    nombre = _nombre;
    tipo = _tipo;
}

Venta::~Venta(){}

void Venta::generarVenta(){}

void Venta::mostrarVenta(){}
