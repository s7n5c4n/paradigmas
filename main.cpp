#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include "include/lista_enlazada.h"
#include "include/ventaVehiculos.h"
#include "include/ventaAccesorios.h"
#include "include/GestorVenta.h"
#include "include/accesorio.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void LeerInventario(ListaEnlazada & autos, ListaEnlazada & motos, ListaEnlazada & camiones) {
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
            
            if (tipo == "auto"){
                autos.insertarAlInicio(new Auto(marca, precio, puertas, ano));
            }else if (tipo == "moto")
            {
                motos.insertarAlInicio(new Moto(marca, precio, puertas, ano));
            }else if (tipo == "camion")
            {
                camiones.insertarAlInicio(new Camion(marca, precio, puertas, ano));
            };
        }
        //lista.imprimirLista();
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void LeerInventarioAccesorios(vector<Accesorio> & autos, vector<Accesorio> & motos, vector<Accesorio> & camiones) {
    ifstream archivo("accesorios.txt");
    
    if (archivo.is_open()) {
        string linea;
        
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            
            string tipo, marca;
            int precio;
            
            getline(ss, tipo, ',');
            getline(ss, marca, ',');
            ss >> precio;
            if (tipo == "auto"){
                autos.push_back(Accesorio(tipo, marca, precio));
            }else if (tipo == "moto")
            {
                motos.push_back(Accesorio(tipo, marca, precio));
            }else if (tipo == "camion")
            {
                camiones.push_back(Accesorio(tipo, marca, precio));
            };
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main(){
    ListaEnlazada listaAutos, listaMotos, listaCamiones;

    vector<Accesorio> accesoriosAuto, accesoriosMotocicleta, accesoriosCamion;

    LeerInventarioAccesorios(accesoriosAuto, accesoriosMotocicleta, accesoriosCamion);
    LeerInventario(listaAutos, listaMotos, listaCamiones);

    GestorVenta gestorVehiculos, gestorAccesorios;
 
    int opcion, cantidadVehiculos, indiceVehiculo;
    
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
                string tipoVehiculo;
                cout << "Ingrese el nombre del cliente: ";
                cin.ignore();
                getline(cin, nombrecliente);
                cout << "Ingrese el rut del cliente: ";
                cin >> rutCliente;
                cout << "Cliente: " << nombrecliente << ", Rut: " << rutCliente << endl;

                // Mostrar opciones de vehículos disponibles
                cout << "Opciones de vehículos disponibles:" << endl;
                cout << "1. Autos\n2. Motos\n3. Camiones" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        cout << "Ingrese el tipo de auto que desea comprar: \n";
                        listaAutos.imprimirLista();
                        cin >> indiceVehiculo;
                        cout << "Ingrese la cantidad de autos que desea comprar: ";
                        cin >> cantidadVehiculos;
                        gestorVehiculos.insertarAlInicio(new VentaVehiculo(rutCliente, nombrecliente, "auto", cantidadVehiculos, listaAutos.obtenerVehiculoIndice(indiceVehiculo), accesoriosAuto));
                        break;
                    case 2:
                        cout << "Ingrese el tipo de moto que desea comprar: \n";
                        listaMotos.imprimirLista();
                        cin >> indiceVehiculo;
                        cout << "Ingrese la cantidad de motos que desea comprar: ";
                        cin >> cantidadVehiculos;
                        gestorVehiculos.insertarAlInicio(new VentaVehiculo(rutCliente, nombrecliente, "moto", cantidadVehiculos, listaMotos.obtenerVehiculoIndice(indiceVehiculo), accesoriosMotocicleta));
                        break;
                    case 3:
                    cout << "Ingrese el tipo de camion que desea comprar: \n";
                        listaCamiones.imprimirLista();
                        cin >> indiceVehiculo;
                        cout << "Ingrese la cantidad de camiones que desea comprar: ";
                        cin >> cantidadVehiculos;
                        gestorVehiculos.insertarAlInicio(new VentaVehiculo(rutCliente, nombrecliente, "camion", cantidadVehiculos, listaCamiones.obtenerVehiculoIndice(indiceVehiculo), accesoriosCamion));
                        break;
                    default:
                        cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
                }
                
                break;

            }
            case 2:{
                string nombrecliente;
                string rutCliente;
                cout << "Ingrese el nombre del cliente: ";
                cin >> nombrecliente;
                cout << "Ingrese el rut del cliente: ";
                cin >> rutCliente;
                
                cout << "Cliente: " << nombrecliente << ", Rut: " << rutCliente << endl;
                cout << "Opciones de accesorios disponibles:" << endl;

                cout << "1. Autos\n2. Motos\n3. Camiones" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        gestorAccesorios.insertarAlInicio(new VentaAccesorios(rutCliente, nombrecliente, "auto", accesoriosAuto));
                        break;
                    case 2:
                        gestorAccesorios.insertarAlInicio(new VentaAccesorios(rutCliente, nombrecliente, "moto", accesoriosMotocicleta));
                        break;
                    case 3:
                        gestorAccesorios.insertarAlInicio(new VentaAccesorios(rutCliente, nombrecliente, "camion", accesoriosCamion));
                        break;
                    default:
                        cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
                }
                break;
            }
            case 3: {
                cout << "1. Por tipo de Vehiculo\n2. Ver total de vehiculos comprados" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        cout << "El promedio de venta de Autos es: "<< gestorVehiculos.obtenerPromedioVentaPorTipo("auto") << endl;
                        cout << "El promedio de venta de Motos es: " << gestorVehiculos.obtenerPromedioVentaPorTipo("moto") << endl;
                        cout << "El promedio de venta de Camiones es: " << gestorVehiculos.obtenerPromedioVentaPorTipo("camion") << endl;
                        break;
                    case 2:
                        gestorVehiculos.imprimirPromedioVenta();
                        break;
                    default:
                        cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
                }
                break;
            }
            case 4:{
                cout << "1. Por tipo de Vehiculo\n2. Ver total de vehiculos comprados" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch(opcion){
                    case 1:
                        cout << "La cantidad de autos comprados es: "<< gestorVehiculos.obtenerCantidadVehiculosCompradosPorTipo("auto") << endl;
                        cout << "La cantidad de motos comprados es: " << gestorVehiculos.obtenerCantidadVehiculosCompradosPorTipo("moto") << endl;
                        cout << "La cantidad de camiones comprados es: " << gestorVehiculos.obtenerCantidadVehiculosCompradosPorTipo("camion") << endl;
                        break;
                    case 2:
                        gestorVehiculos.imprimirCantidadVehiculosComprados();
                        break;
                    default:
                        cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
                }
                break;
            }
            case 5:{
                cout << "Saliendo del programa..." << endl;
                //Vehiculos
                gestorVehiculos.imprimirClientequeComproMasVehiculosPorTipo("auto");
                gestorVehiculos.imprimirClientequeComproMasVehiculosPorTipo("moto");
                gestorVehiculos.imprimirClientequeComproMasVehiculosPorTipo("camion");
                gestorVehiculos.imprimirClientequeComproMasVehiculos();

                //Accesorios
                gestorAccesorios.imprimirClientequeComproMasVehiculosPorTipo("auto");
                gestorAccesorios.imprimirClientequeComproMasVehiculosPorTipo("moto");
                gestorAccesorios.imprimirClientequeComproMasVehiculosPorTipo("camion");
                gestorAccesorios.imprimirClientequeComproMasAccesorios();
                break;
                }
            default: {
                cout << "Opcion no valida, porfavor ingresa una opcion valida." << endl;
            }
        }
    } while(opcion != 5);
    cout << endl;
    return 0;
}

