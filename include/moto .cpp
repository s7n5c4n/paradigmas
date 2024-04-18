#include "moto.h"
#include <iostream>

using namespace std;

Moto::Moto(string _marca, int _precio, int _cantidadRuedas, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _yearFabricacion){
    controlRemoto = false;
};

Moto:: ~Moto(){
    cout << "Se elimino la Moto" << endl;
};

void Moto::mostrarDetalles(){
    cout << "Marca de la Moto: " << marca << endl;
    cout << "Precio de la Moto: " << precio << endl;
    cout << "Cantidad de la Moto: " << cantidadRuedas << endl;
    cout << "El Moto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion de la Moto: " << yearFabricacion << endl;
};