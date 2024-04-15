#include "vehiculo.h"
#include <iostream>

using namespace std;

Vehiculo::Vehiculo(string _marca, int _precio, int _cantidadRuedas, bool _controlRemoto, int _yearFabricacion){
    marca = _marca;
    precio = _precio;
    cantidadRuedas = _cantidadRuedas;
    controlRemoto = _controlRemoto;
    yearFabricacion = _yearFabricacion;

    cout << "Se creo el vehiculo"<<endl;
};

void Vehiculo::agregarAccesorio(const string& nombre, int precio) {
    accesorios.push_back(Accesorio(nombre, precio));
}

Vehiculo::Accesorio Vehiculo::obtenerAccesorio(int indice) const {
    if (indice >= 0 && indice < accesorios.size()) {
        return accesorios[indice];
    } else {
        return Accesorio("", 0);
    }
}
