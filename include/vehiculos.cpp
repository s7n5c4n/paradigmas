#include <iostream>
#include "vehiculos.h"

using namespace std;

Vehiculo::Vehiculo(int _cantidadRuedas, string _marca, bool _controlRemoto, int _yearFabricacion){
    cout << "Se creo" << endl;
    cantidadRuedas = _cantidadRuedas;
    marca =  _marca;
    controlRemoto = _controlRemoto;
    yearFabricacion = _yearFabricacion;
}

Vehiculo::~Vehiculo(){
    cout << "Se destruyo" << endl;
};
