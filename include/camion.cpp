#include "camion.h"
#include <iostream>

using namespace std;

Camion::Camion(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio)
    : Vehiculo(4, marca, true, 2022, precio) {}

void Camion::agregarAccesorios() {
    agregarAccesorio("Caja", 10000);
    agregarAccesorio("Ejes", 8000);
}

void Camion::mostrarDetalles() const {
    cout << "Camion: Marca " << marca << endl;
    cout << "Precio: " << precio << endl;
    cout << "Cantidad de ruedas: " << cantidadRuedas << endl;
    cout << "Control remoto: " << (controlRemoto ? "Sí" : "No") << endl;
    cout << "Año de fabricación: " << yearFabricacion << endl;
    mostrarAccesorios();
}