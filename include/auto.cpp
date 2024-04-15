#include "auto.h"
#include <iostream>
#include <vector>

using namespace std;

Auto::Auto(string _marca, int _precio, int _cantidadRuedas, bool _controlRemoto, int _yearFabricacion) : Vehiculo( _marca, _precio,  _cantidadRuedas, _controlRemoto, _yearFabricacion){};

Auto:: ~Auto(){
    cout << "Se elimino el auto" << endl;
};

void Auto::mostrarAccesorios(){
    if (accesorios.empty()) {
        cout << "El Auto no tiene accesorios." << endl;
    } else {
        cout << "Accesorios del Auto:" << endl;
        for (const auto& accesorio : accesorios) {
            cout << "Nombre: " << accesorio.nombre << ", Precio: " << accesorio.precio << endl;
        }
    }
};

void Auto::mostrarDetalles(){
    cout << "Marca del Auto:" << marca << endl;
    cout << "Precio del Auto: " << precio << endl;
    cout << "Cantidad del Auto: " << cantidadRuedas << endl;
    cout << "El Auto tiene Control remoto: " << (controlRemoto ? "Si" : "No") << endl;
    cout << "Anio de fabricacion del Auto: " << yearFabricacion << endl;
    mostrarAccesorios();
};


