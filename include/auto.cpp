#include "auto.h"
#include <iostream>

using namespace std;

Auto::Auto(string _marca, int _precio, int _cantidadRuedas, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _yearFabricacion){
    controlRemoto = true;
};

Auto:: ~Auto(){
    cout << "Se elimino el auto" << endl;
};

void Auto::mostrarDetalles(){
    cout << "Marca del Auto: " << marca << endl;
    cout << "Precio del Auto: " << precio << endl;
    cout << "Cantidad del Auto: " << cantidadRuedas << endl;
    cout << "El Auto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion del Auto: " << yearFabricacion << endl;
};


