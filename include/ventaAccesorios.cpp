#include "ventaAccesorios.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

VentaAccesorios::VentaAccesorios(string _rut, string _nombre, string _tipo, vector <Accesorio> & _accesoriosIniciales) : Venta(_rut, _nombre, _tipo), accesoriosIniciales(_accesoriosIniciales){
    
    accesoriosIniciales = _accesoriosIniciales;
    cantidad = accesoriosIniciales.size();
    int opcion;
    
    do
    {
        for (int i = 0; i < accesoriosIniciales.size(); i++) {
            cout << i+1 << ". " << accesoriosIniciales[i].nombre << ": " << accesoriosIniciales[i].precio << endl;
        }
        cout << "Ingrese una opcion: ";

        cin >> opcion;
        cout << "Cuanto desea comprar:";
        cin >> cantidad;
        for (int i = 0; i < accesoriosIniciales.size(); i++) {
            if (opcion == i+1) {
                totalPrecioAccesorios += accesoriosIniciales[i].precio * cantidad;
            }
        }
        cout << "Total: " << totalPrecioAccesorios << endl;
        cout << "Desea comprar algo mas? (1. Si, 2. No): ";
        
    } while ( opcion != cantidad );
    
};

VentaAccesorios::~VentaAccesorios(){};

int VentaAccesorios::obtenerCantidadArticulos(){
    return cantidad;

};

int VentaAccesorios::obtenerTotalVenta() {
    return totalPrecioAccesorios;
};

string VentaAccesorios::obtenerTipoArticulo() {
    return tipo;
};

void VentaAccesorios::mostrarVenta() {
    cout << "Venta de accesorios" << endl;
    cout << "Rut: " << rut << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo de articulo: " << tipo << endl;
    cout << "Cantidad de articulos: " << cantidad << endl;
    cout << "Total de la venta: " << totalPrecioAccesorios << endl;
};

void VentaAccesorios::generarVenta() {
    ofstream archivo("ventas.txt", ios::app);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    archivo << "Venta de accesorios" << endl;
    archivo << "Rut: " << rut << endl;
    archivo << "Nombre: " << nombre << endl;
    archivo << "Tipo de articulo: " << tipo << endl;
    archivo << "Cantidad de articulos: " << cantidad << endl;
    archivo << "Total de la venta: " << totalPrecioAccesorios << endl;
    archivo << "Fecha: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    archivo << "Hora: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    archivo << "--------------------------------" << endl;
    archivo.close();
};

