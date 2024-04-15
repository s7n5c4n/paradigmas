#include "moto.h"
#include <iostream>

using namespace std;

Moto::Moto(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio)
    : Vehiculo(2, marca, false, 2023, precio) {}

void Moto::agregarAccesorios() {
    agregarAccesorio("Pedales", 10000);
    agregarAccesorio("Ejes", 8000);
}

void Moto::mostrarDetalles() const {
    cout << "Moto: Marca " << marca << endl;
    cout << "Precio: " << precio << endl;
    cout << "Cantidad de ruedas: " << cantidadRuedas << endl;
    cout << "Control remoto: " << (controlRemoto ? "Sí" : "No") << endl;
    cout << "Año de fabricación: " << yearFabricacion << endl;
    mostrarAccesorios();
}