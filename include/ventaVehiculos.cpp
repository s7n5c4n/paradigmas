#include <iostream>
#include <fstream>
#include "ventaVehiculos.h"

using namespace std;

VentaVehiculo::VentaVehiculo(string _rut, string _nombre, string _tipo, int _cantidadVehiculos, Vehiculo* _vehiculo, vector <Accesorio> & _accesoriosIniciales) : Venta(_rut, _nombre, _tipo), accesoriosIniciales(_accesoriosIniciales){
    cantidadVehiculos = _cantidadVehiculos;
    vehiculo = _vehiculo;
    
    int opcion;

    do
    {
        cout << "Desea agregar accesorios? (1. Si, 2. No): ";
        cin >> opcion;
        if (opcion == 2) {
            generarVenta();
            agregarVenta();
            break;
        }
        else if (opcion == 1)
        {
            VentaAccesorios ventaAccesorios(_rut, _nombre, _tipo, _accesoriosIniciales);
            cantidadAccesorios = ventaAccesorios.obtenerCantidadArticulos();
            totalPrecioAccesorios = ventaAccesorios.obtenerTotalVenta();
            generarVenta();
            agregarVenta();
            break;
        }
        else
        {
            cout << "Opcion no valida" << endl;
        }
    } while (true);
}

VentaVehiculo::~VentaVehiculo(){}

int VentaVehiculo::obtenerCantidadArticulos(){
    return cantidadVehiculos;
};

int VentaVehiculo::obtenerTotalVenta(){
    return totalGeneral;
};

void VentaVehiculo::mostrarVenta(){
    cout << "CLIENTE: " << nombre << endl;
    cout << "RUT: " << rut << endl;
    cout << "CANTIDAD (Vehiculos Total): " << cantidadVehiculos << endl;
    cout << "CANTIDAD (Accesorios Total): " << cantidadAccesorios << endl;
    cout << "Total precio Accesorios: $" << 0 << endl;
    cout << "TOTAL precio Vehiculos: $" << totalPrecioVehiculos << endl;
    cout << "TOTAL con descuento "<< descuento*100 <<"%: $" << totalDescuento << endl;
    cout << "TOTAL GENERAL: $" << totalGeneral << endl;
}

void VentaVehiculo::generarVenta(){
    
    if (cantidadVehiculos > 10000) {
        descuento = 0.1;
    }
    else if (5000 <cantidadVehiculos<1000)
    {
        descuento = 0.05;
    }
    else if (1000 < cantidadVehiculos < 4999)
    {
        descuento = 0.03;
    }
    else if (1000 > cantidadVehiculos)
    {
        descuento = 0.01;
    }
    else{
        descuento = 0.0f;
    }

    totalPrecioVehiculos = vehiculo->precio*cantidadVehiculos;

    totalDescuento = totalPrecioVehiculos - totalPrecioVehiculos * descuento;
    
    totalGeneral = totalDescuento + totalPrecioAccesorios;
}

string VentaVehiculo::obtenerTipoArticulo(){
    return vehiculo->tipo;
}

void VentaVehiculo::agregarVenta(){
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d", timeinfo);
    string fecha(buffer);

    string nombreArchivo = rut + "_" + fecha + ".txt";
    string rutaCarpeta = "./ventas-vehiculos/";

    ofstream archivo(rutaCarpeta + nombreArchivo);
    if (archivo.is_open()) {
        archivo << "CLIENTE: " << nombre << endl;
        archivo << "RUT: " << rut << endl;
        archivo << "CANTIDAD (Vehiculos Total): " << cantidadVehiculos << endl;
        archivo << "CANTIDAD (Accesorios Total): " << cantidadAccesorios << endl;
        archivo << "Total precio Accesorios: $" << totalPrecioAccesorios << endl;
        archivo << "TOTAL precio Vehiculos: $" << totalPrecioVehiculos << endl;
        archivo << "TOTAL con descuento "<< descuento*100 <<"%: $" << totalDescuento << endl;
        archivo << "TOTAL GENERAL: $" << totalGeneral << endl;
        archivo.close();
        cout << "Venta agregada al archivo venta.txt" << endl;
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

