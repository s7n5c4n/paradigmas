#include "Auto.h"
#include <iostream>

using namespace std;

Auto::Auto(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio)
    : Vehiculo(4, marca, true, 2023, precio) {}

void Auto::agregarAccesorios() {
    agregarAccesorio("Puertas", 1000);
    agregarAccesorio("Luces", 600);
}

void Auto::mostrarDetalles() const {
    cout << "Auto: Marca " << marca << endl;
    cout << "Precio: " << precio << endl;
    cout << "Cantidad de ruedas: " << cantidadRuedas << endl;
    cout << "Control remoto: " << (controlRemoto ? "Sí" : "No") << endl;
    cout << "Año de fabricación: " << yearFabricacion << endl;
    mostrarAccesorios();
}

