#include <iostream>
#include "venta.h"
#include <fstream>

using namespace std;

Venta::Venta(string _rut, string _nombre, string _tipo, int _cantidadVehiculos, int _cantidadAccesorio, Vehiculo* _vehiculo){
    rut = _rut;
    nombre = _nombre;
    tipo = _nombre;
    cantidadVehiculos = _cantidadVehiculos;
    cantidadAccesorios = _cantidadAccesorio;
    vehiculo = _vehiculo;
    generarVenta();
}

Venta::~Venta(){}

int Venta::obtenerCantidadVehiculosComprados(){
    return cantidadVehiculos;
};

int Venta::obtenerTotalVenta(){
    return totalGeneral;
};

void Venta::guardarVenta(){
    ofstream archivo("hola.txt");
        if (archivo.is_open()) {
            archivo << "CLIENTE: " << nombre << endl;
            archivo << "RUT: " << rut << endl;
            archivo << "CANTIDAD (Vehículos Total): " << cantidadVehiculos << endl;
            archivo << "CANTIDAD (Accesorios Total): " << cantidadAccesorios << endl;
            archivo << "Total precio Accesorios: $" << 0 << endl;
            archivo << "TOTAL precio Vehiculos: $" << totalPrecioVehiculos << endl;
            archivo << "TOTAL con descuento"<< descuento <<": $" << totalDescuento << endl;
            archivo << "TOTAL GENERAL: $" << totalGeneral << endl;
            archivo.close();
            cout << "Información del cliente guardada correctamente en "<< endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar la información del cliente." << endl;
        }
}

void Venta::generarVenta(){
    float descuento;
    
    if (cantidadVehiculos > 1000) {
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
    
    int totalPrecioAccesorios = 0;

    totalDescuento = totalPrecioVehiculos - totalPrecioVehiculos * descuento;
    
    totalGeneral = totalDescuento + totalPrecioAccesorios;
}

