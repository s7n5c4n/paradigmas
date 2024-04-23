#include "ventaAccesorios.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>

using namespace std;

VentaAccesorios::VentaAccesorios(string _rut, string _nombre, string _tipo, vector <Accesorio> & _accesoriosIniciales) : Venta(_rut, _nombre, _tipo), accesoriosIniciales(_accesoriosIniciales){
    
    accesoriosIniciales = _accesoriosIniciales;
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
                if (!accesorios.empty() && buscarAccesorio(accesoriosIniciales, accesorios, i)) {
                    cout << "Ya ha comprado este accesorio\n" << endl;
                } else {
                    totalPrecioAccesorios += accesoriosIniciales[i].precio * cantidad;
                    agregarAccesorio(accesoriosIniciales[i], cantidad);
                }
            };
        }

        cout << "Total: " << totalPrecioAccesorios << endl;
        cout << "\nDesea comprar algo mas? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 2) {
            generarVenta();
            break;
        };
        
    } while ( true );
    
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

void VentaAccesorios::agregarAccesorio(Accesorio accesorio, int cantidad) {
    AccesorioCantidad accesorioCantidad(accesorio, cantidad);
    cantidad += cantidad;
    accesorios.push_back(accesorioCantidad);
};
    
bool VentaAccesorios::buscarAccesorio(vector<Accesorio> &accesoriosIniciales, vector<AccesorioCantidad> &accesorios, int numero){
    for (int i = 0; i < accesorios.size(); i++) {
        if (accesorios[i].accesorio.nombre == accesoriosIniciales[numero].nombre) {
            return true;
        }
    }
    return false;
}

void VentaAccesorios::mostrarVenta() {
    cout << "Venta de accesorios" << endl;
    cout << "Rut: " << rut << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo de articulo: " << tipo << endl;
    cout << "Cantidad de articulos: " << cantidad << endl;
    cout << "Total de la venta: " << totalPrecioAccesorios << endl;
};

void VentaAccesorios::generarVenta() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d", timeinfo);
    string fecha(buffer);

    string nombreArchivo = rut + "_" + fecha + ".txt";
    string rutaCarpeta = "./ventas-accesorios/";

    ofstream archivo(rutaCarpeta + nombreArchivo);

    tm *ltm = localtime(&now);
    archivo << "Venta de accesorios" << endl;
    archivo << "Rut: " << rut << endl;
    archivo << "Nombre: " << nombre << endl;
    for (int i = 0; i < accesorios.size(); i++) {
        archivo << "Accesorio: " << accesorios[i].accesorio.nombre << endl;
        archivo << "Cantidad: " << accesorios[i].cantidad << endl;
    }
    archivo << "Total de la venta: " << totalPrecioAccesorios << endl;
    archivo << "Fecha: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    archivo << "Hora: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    archivo << "--------------------------------" << endl;
    archivo.close();
};

