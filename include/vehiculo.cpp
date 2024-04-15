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

Vehiculo::Accesorio Vehiculo::obtenerAccesorio(int indice) {
    if (indice >= 0 && indice < accesorios.size()) {
        return accesorios[indice];
    } else {
        return Accesorio("", 0);
    }
}

void Vehiculo::mostrarAccesorios(){
    if (accesorios.empty()) {
        cout << "El vehículo no tiene accesorios." << endl;
    } else {
        cout << "Accesorios del vehículo:" << endl;
        for (const auto& accesorio : accesorios) {
            cout << "Nombre: " << accesorio.nombre << ", Precio: " << accesorio.precio << endl;
        }
    }
};

void Vehiculo::mostrarDetalles(){
    cout << "Marca del Vehiculo: Marca " << marca << endl;
    cout << "Precio del Vehiculo: " << precio << endl;
    cout << "Cantidad del Vehiculo: " << cantidadRuedas << endl;
    cout << "El Vehiculo tiene Control remoto: " << (controlRemoto ? "Sí" : "No") << endl;
    cout << "Año de fabricación del Vechiculo: " << yearFabricacion << endl;
    mostrarAccesorios();
};
