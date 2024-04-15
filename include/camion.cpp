#include "camion.h"
#include <iostream>
#include <vector>

using namespace std;

Camion::Camion(string _marca, int _precio, int _cantidadRuedas, bool _controlRemoto, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _controlRemoto, _yearFabricacion){};

Camion:: ~Camion(){
    cout << "Se elimino el camion" << endl;
};

void Camion::mostrarAccesorios(){
    if (accesorios.empty()) {
        cout << "El Camion no tiene accesorios." << endl;
    } else {
        cout << "Accesorios de el Camion:" << endl;
        for (const auto& accesorio : accesorios) {
            cout << "Nombre: " << accesorio.nombre << ", Precio: " << accesorio.precio << endl;
        }
    }
};

void Camion::mostrarDetalles(){
    cout << "Marca de el Camion: " << marca << endl;
    cout << "Precio de el Camion: " << precio << endl;
    cout << "Cantidad de el Camion: " << cantidadRuedas << endl;
    cout << "El Moto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion de el Camion: " << yearFabricacion << endl;
    mostrarAccesorios();
};