#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void realizarAccion(Vehiculo* vehiculo) {
    if (dynamic_cast<Auto*>(vehiculo)) {
        int accesorio = vehiculo->obtenerAccesorio(1).precio;
        cout << "Accesorio precio: " << accesorio << endl;
    };
};

void mostrarInventario(Vehiculo** inventario, int tamano) {
    for (int i = 0; i < tamano; ++i) {
        cout << (i + 1) << ". "<< inventario[i]->marca << ": " << inventario[i]->precio << endl;
        cout << endl;
    }
}

int main(){

    Vehiculo *Autos[5];
    Vehiculo *Motos[5];
    Vehiculo *Camiones[5];

    int opcion;

    //Autos
    Autos[0] = new Auto("Toyota", 19000, 4, true, 2002);
    Autos[1] = new Auto("Hyundai", 16000, 4, true, 2020);
    Autos[2] = new Auto("Susuki", 12000, 4, true, 2014);
    Autos[3] = new Auto("Ford", 17000, 4, true, 2016);
    Autos[4] = new Auto("Chevrolet", 18000, 4, true, 2018);
    Autos[5] = new Auto("Honda", 21000, 4, true, 2023);
    //Motos
    Motos[0] = new Moto("Yamaha", 14000, 4, true, 2002);
    Motos[1] = new Moto("Susuki", 8000, 4, true, 2024);
    Motos[2] = new Moto("Honda", 15000, 4, true, 2014);
    Motos[3] = new Moto("KTM", 5000, 4, true, 2011);
    Motos[4] = new Moto("BWM", 18000, 4, true, 2010);
    Motos[5] = new Moto("Kawasaki", 13000, 4, true, 2023);
    //Camiones
    Camiones[0] = new Camion("Volvo", 100000, 4, true, 2002);
    Camiones[1] = new Camion("Iveco", 85000, 4, true, 2024);
    Camiones[2] = new Camion("Mercedes", 110000, 4, true, 2014);
    Camiones[3] = new Camion("Isuzu", 70000, 4, true, 2011);
    Camiones[4] = new Camion("MAN", 105000, 4, true, 2010);
    Camiones[5] = new Camion("Scania", 95000, 4, true, 2023);
    cout << endl;
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                ventaVehiculo(ventas);
                break;
            case 2:
                calcularPromedioVentas(ventas);
                break;
            case 3:
                mostrarCantidadVehiculos(ventas);
                break;
            case 4:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);
    for (Ventas& venta : ventas) {
        delete venta.vehiculo; 
    }
    return 0;

    mostrarInventario(Camiones,6);

    return 0;
}

