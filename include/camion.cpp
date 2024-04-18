#include "camion.h"
#include <iostream>

using namespace std;

Camion::Camion(string _marca, int _precio, int _cantidadRuedas, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _yearFabricacion){
    controlRemoto = true;
};

Camion:: ~Camion(){
    cout << "Se elimino el camion" << endl;
};

void Camion::mostrarDetalles(){
    cout << "Marca de el Camion: " << marca << endl;
    cout << "Precio de el Camion: " << precio << endl;
    cout << "Cantidad de el Camion: " << cantidadRuedas << endl;
    cout << "El Moto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion de el Camion: " << yearFabricacion << endl;
};