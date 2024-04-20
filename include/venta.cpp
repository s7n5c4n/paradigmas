#include <iostream>
#include "venta.h"
#include <fstream>

using namespace std;

Venta::Venta(string _rut, string _nombre){
    rut = _rut;
    nombre = _nombre;
}

Venta::~Venta(){}
