#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include "include/lista_enlazada.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

// void liberarLista(Vehiculo* inicio){
//     while (inicio != nullptr){
//         Vehiculo* temp = inicio;
//         inicio = inicio->siguiente;
//         delete temp;
//     }
// }

// void LeerInventario(Vehiculo* inicio){
//     std::ifstream archivo("inventario.txt");
//     if (archivo.is_open()){
//         string tipo, marca;
//         int precio, puertas, ano;
//         bool estado;

//         while (archivo >> tipo >> marca >> precio >> puertas >> estado >> ano){
//             Vehiculo* nuevoVehiculo = new Vehiculo;
//             nuevoVehiculo->tipo = tipo;
//             nuevoVehiculo->marca = marca;
//             nuevoVehiculo->precio = precio;
//             nuevoVehiculo->puertas = puertas;
//             nuevoVehiculo->estado = estado;
//             nuevoVehiculo->ano = ano;
//             nuevoVehiculo->siguiente = nullptr;

//             if (inicio == nullptr){
//                 incio = nuevoVehiculo;
//             } else{
//                 Vehiculo* actual = inicio;
//                 while (actual->siguiente != nullptr){
//                     actual = actual->siguiente;
//                 }
//                 actual->siguiente = nuevoVehiculo;
//             }
//         }
//         archivo.close()
//     } else{
//         std::cout << "Error al abirr el archivo." << std::endl;
//     }
// }

int main(){

    // Vehiculo* inicio = nullptr;

    // LeerInventario(inicio);
    
    

    // Vehiculo *Autos[5];
    // Vehiculo *Motos[5];
    // Vehiculo *Camiones[5];
    // Venta venta;
    int opcion;


    //Autos
    // Auto1 = new Auto("Toyota", 19000, 4, true, 2002);
    // listaVehiculos.insertarAlInicio(Auto1);
    // listaVehiculos.imprimirLista();
    // Autos[1] = new Auto("Hyundai", 16000, 4, true, 2020);
    // Autos[2] = new Auto("Susuki", 12000, 4, true, 2014);
    // Autos[3] = new Auto("Ford", 17000, 4, true, 2016);
    // Autos[4] = new Auto("Chevrolet", 18000, 4, true, 2018);
    // Autos[5] = new Auto("Honda", 21000, 4, true, 2023);
    //Motos
    // Motos[0] = new Moto("Yamaha", 14000, 4, true, 2002);
    // Motos[1] = new Moto("Susuki", 8000, 4, true, 2024);
    // Motos[2] = new Moto("Honda", 15000, 4, true, 2014);
    // Motos[3] = new Moto("KTM", 5000, 4, true, 2011);
    // Motos[4] = new Moto("BWM", 18000, 4, true, 2010);
    // Motos[5] = new Moto("Kawasaki", 13000, 4, true, 2023);
    //Camiones
    // Camiones[0] = new Camion("Volvo", 100000, 4, true, 2002);
    // Camiones[1] = new Camion("Iveco", 85000, 4, true, 2024);
    // Camiones[2] = new Camion("Mercedes", 110000, 4, true, 2014);
    // Camiones[3] = new Camion("Isuzu", 70000, 4, true, 2011);
    // Camiones[4] = new Camion("MAN", 105000, 4, true, 2010);
    // Camiones[5] = new Camion("Scania", 95000, 4, true, 2023);
    
    do {
        cout << "\n*************************************" << endl;
        cout << "           Menu de opciones:" <<endl;
        cout << "************************************" << endl;
        cout << "1. Venta de Vehiculos a clientes" <<endl;
        cout << "2. Venta de accesorios" <<endl;
        cout << "3. Promedio de ventas" <<endl;
        cout << "4. Cantidad de vehiculos comprados" <<endl;
        cout << "5. Salir" <<endl;
        cout << "Ingrese una opcion: ";

        cin >> opcion;

        switch(opcion){
            case 1:{
                string nombrecliente;
                string rutCliente;
                cout << "Ingrese el nombre del cliente: ";
                cin.ignore();
                getline(cin, nombrecliente);
                cout << "Ingrese el rut del cliente: ";
                getline(cin, rutCliente);
                cout << nombrecliente << rutCliente << endl;
                // venta.VenderVehiculo(nombreCliente, rutCliente);
                break;

            }
            case 2:{
                string nombrecliente;
                string rutCliente;
                cout << "Ingrese el nombre del cliente: ";
                cin.ignore();
                getline(cin, nombrecliente);
                cout << "Ingrese el rut del cliente: ";
                getline(cin, rutCliente);

                // venta.VenderAccesorio(nombreCliente, rutCliente);
                break;
            }
            case 3:
                // venta.ObtenerPromedioVentaTipo();
                break;
            case 4:
                // venta.ObtenerTotalVehiculosCompradosPorTipo();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
        }
    } 
    while(opcion != 5);
    // //aca depues liberar memoria

    // Vehiculo* actual = inicio;
    // while (actual != nullptr){
    //     cout << actual->tipo << ", " << actual->marca << ", " << actual->precio
    //          << ", " << actual->puertas << ", " << actual->estado << ", " << actual->ano << endl;
    //     actual = actual->siguiente;
    // }

    // liberarLista(inicio);

    cout << endl;
    return 0;
}

