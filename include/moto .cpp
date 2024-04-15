#include "moto.h"
#include <iostream>
#include <vector>

using namespace std;

Moto::Moto(string _marca, int _precio, int _cantidadRuedas, bool _controlRemoto, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _controlRemoto, _yearFabricacion){};

Moto:: ~Moto(){
    cout << "Se elimino la Moto" << endl;
};

void Moto::mostrarAccesorios(){
    if (accesorios.empty()) {
        cout << "La Moto no tiene accesorios." << endl;
    } else {
        cout << "Accesorios de la Moto:" << endl;
        for (const auto& accesorio : accesorios) {
            cout << "Nombre: " << accesorio.nombre << ", Precio: " << accesorio.precio << endl;
        }
    }
};

void Moto::mostrarDetalles(){
    cout << "Marca de la Moto: " << marca << endl;
    cout << "Precio de la Moto: " << precio << endl;
    cout << "Cantidad de la Moto: " << cantidadRuedas << endl;
    cout << "El Moto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion de la Moto: " << yearFabricacion << endl;
    mostrarAccesorios();
};