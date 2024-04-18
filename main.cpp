#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include "include/lista_enlazada.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>


using namespace std;

void LeerInventario(ListaEnlazada & lista) {
    ifstream archivo("inventario.txt");
    
    if (archivo.is_open()) {
        string linea;
        
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            
            string tipo, marca;
            int precio, puertas, ano;
            
            getline(ss, tipo, ',');
            getline(ss, marca, ',');
            ss >> precio;
            ss.ignore();
            ss >> puertas;
            ss.ignore(); 
            ss >> ano;
            
            if (tipo == "Auto"){
                lista.insertarAlInicio(new Auto(marca, precio, puertas, ano));
            }else if (tipo == "Moto")
            {
                lista.insertarAlInicio(new Moto(marca, precio, puertas, ano));
            }else if (tipo == "Camion")
            {
                lista.insertarAlInicio(new Camion(marca, precio, puertas, ano));
            };
        }
        //lista.imprimirLista();
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main(){
    ListaEnlazada listaVehiculos;

    LeerInventario(listaVehiculos);
    listaVehiculos.imprimirLista();
    GestorVenta gestorVenta;
 
    int opcion;
    
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
                cout << "Cliente: " << nombrecliente << ", Rut: " << rutCliente << endl;

                // Mostrar opciones de vehículos disponibles
                cout << "Opciones de vehículos disponibles:" << endl;
                gestorVenta.VenderVehiculo(nombreCliente, rutCliente); 
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

