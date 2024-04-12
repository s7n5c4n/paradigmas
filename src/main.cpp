#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Función principal
int main() {
    // Variables y contenedores necesarios
    vector<Vehiculo*> inventarioVehiculos;
    vector<Accesorio> inventarioAccesorios;
    ManejadorVentas manejador;

    // Lógica del menú de opciones
    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Venta de vehiculos" << endl;
        cout << "2. Venta de accesorios" << endl;
        cout << "3. Promedio de ventas" << endl;
        cout << "4. Cantidad total de vehículos comprados" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Lógica para realizar una venta de vehículos
                string nombreCliente, rutCliente;
                int cantidadVehiculos;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese RUT del cliente: ";
                cin >> rutCliente;
                cout << "Ingrese cantidad de vehículos a comprar: ";
                cin >> cantidadVehiculos;

                Cliente cliente(nombreCliente, rutCliente);
                manejador.venderVehiculos(inventarioVehiculos, cliente, cantidadVehiculos);
                break;
            }
            case 2: {
                // Lógica para realizar una venta de accesorios
                string nombreCliente, rutCliente, nombreAccesorio;
                int cantidadAccesorios;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese RUT del cliente: ";
                cin >> rutCliente;
                cout << "Ingrese nombre del accesorio: ";
                cin >> nombreAccesorio;
                cout << "Ingrese cantidad de accesorios a comprar: ";
                cin >> cantidadAccesorios;

                Cliente cliente(nombreCliente, rutCliente);
                Accesorio accesorio(nombreAccesorio, 1000); // Precio de ejemplo, ajustar según sea necesario
                inventarioAccesorios.push_back(accesorio);
                manejador.venderAccesorios(inventarioAccesorios, cliente, cantidadAccesorios);
                break;
            }
            case 3: {
                // Lógica para mostrar promedio de ventas
                double promedio = manejador.promedioVentas();
                cout << "Promedio de ventas: $" << promedio << endl;
                break;
            }
            case 4: {
                // Lógica para mostrar cantidad total de vehículos comprados
                int total = manejador.cantidadTotalVehiculos();
                cout << "Cantidad total de vehículos comprados: " << total << endl;
                break;
            }
            case 5:
                // Lógica para salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 5." << endl;
        }
    } while (opcion != 5);

    // Liberar memoria de los vehículos
    for (auto vehiculo : inventarioVehiculos) {
        delete vehiculo;
    }

    // Almacenar ventas antes de salir
    manejador.almacenarVentas();

    return 0;
}

