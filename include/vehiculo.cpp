#include "vehiculo.h"
#include <iostream>

using namespace std;

Vehiculo::Vehiculo(string _marca, int _precio, int _cantidadRuedas, int _yearFabricacion){
    marca = _marca;
    precio = _precio;
    cantidadRuedas = _cantidadRuedas;
    yearFabricacion = _yearFabricacion;

    cout << "Se creo el vehiculo"<<endl;
};

Vehiculo::~Vehiculo(){};

void Vehiculo::mostrarDetalles(){
    cout << "Marca del Vehiculo: " << marca << endl;
    cout << "Precio del Vehiculo: " << precio << endl;
    cout << "Cantidad del Vehiculo: " << cantidadRuedas << endl;
    cout << "El Vehiculo tiene Control remoto: " << (controlRemoto ? "Sí" : "No") << endl;
    cout << "Año de fabricación del Vechiculo: " << yearFabricacion << endl;
};
