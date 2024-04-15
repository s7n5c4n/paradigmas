#include "vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio)
    : cantidadRuedas(cantidadRuedas), marca(marca), controlRemoto(controlRemoto), yearFabricacion(yearFabricacion), precio(precio) {}

Vehiculo::~Vehiculo() {}

void Vehiculo::agregarAccesorio(const string& nombre, int precio) {
    accesorios.push_back(Accesorio(nombre, precio));
}

void Vehiculo::mostrarAccesorios() const {
    if (accesorios.empty()) {
        cout << "El vehículo no tiene accesorios." << endl;
    } else {
        cout << "Accesorios del vehículo:" << endl;
        for (const auto& accesorio : accesorios) {
            cout << "Nombre: " << accesorio.nombre << ", Precio: " << accesorio.precio << endl;
        }
    }
}

Vehiculo::Accesorio Vehiculo::obtenerAccesorio(int indice) const {
    if (indice >= 0 && indice < accesorios.size()) {
        return accesorios[indice];
    } else {
        return Accesorio("", 0);
    }
}
