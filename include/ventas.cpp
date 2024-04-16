#include "ventas.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

Venta::Venta(string _rut, string _nombre, int _cantidadJuguetes, int _cantidadAccesorios, Vehiculo* _vehiculo){
    rut = _rut;
    nombre = _nombre;
    cantidadJuguetes = _cantidadJuguetes;
    cantidadAccesorios =_cantidadAccesorios;
    vehiculo = _vehiculo;
}

Venta::~Venta(){};

void Venta::asignacionDescuento(){
    if (cantidadJuguetes > 1000) {
        descuento = 0.1;
    }
    else if (5000 <cantidadJuguetes<1000)
    {
        descuento = 0.05;
    }
    else if (1000 < cantidadJuguetes < 4999)
    {
        descuento = 0.03;
    }
    else if (1000 > cantidadJuguetes)
    {
        descuento = 0.01;
    }
    else{
        descuento = NULL;
    }
}

void Venta::ventaCliente(){
    asignacionDescuento();
    totalPrecioVehiculos = vehiculo->precio*cantidadJuguetes;
    totalPrecioAccesorios = vehiculo->obtenerPrecioAccesorios()*cantidadAccesorios;

    totalDescuento = totalPrecioVehiculos - totalPrecioVehiculos * descuento;
    
    totalGeneral = totalDescuento + totalPrecioAccesorios;
}

int Venta::obtenerCantidadVehiculos(){
    return cantidadJuguetes;
}

int Venta::obtenerPrecioTotalVehiculos(){
    return totalPrecioVehiculos;
}

void Venta::obtenerTipoVehiculo(){
    return vehiculo
}

void Venta::guardarDetalleVenta(){
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    struct tm* timeinfo = localtime(&now_time);

    stringstream ss;
    ss << put_time(timeinfo, "%Y%m%d_%H%M%S");
    string fechaHora = ss.str();

    string nombreArchivo = rut + "_" + fechaHora + ".txt";
    ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << "CLIENTE: " << nombre << endl;
            archivo << "RUT: " << rut << endl;
            archivo << "CANTIDAD (Vehículos Total): " << cantidadJuguetes << endl;
            archivo << "CANTIDAD (Accesorios Total): " << cantidadAccesorios << endl;
            archivo << "Total precio Accesorios: $" << totalPrecioAccesorios << endl;
            archivo << "TOTAL precio Vehiculos: $" << totalPrecioVehiculos << endl;
            archivo << "TOTAL con descuento"<< descuento <<": $" << totalDescuento << endl;
            archivo << "TOTAL GENERAL: $" << totalGeneral << endl;
            archivo.close();
            cout << "Información del cliente guardada correctamente en "<< nombreArchivo << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar la información del cliente." << endl;
        }
}



