#include "Venta.h"

void Venta::agregarCliente(const std::string& nombre, int rut) {
    clientes.emplace_back(nombre, rut);
}

void Venta::agregarAuto(Auto* auto_) {
    autos.push_back(auto_);
}

void Venta::agregarMoto(Moto* moto) {
    motos.push_back(moto);
}

void Venta::agregarCamion(Camion* camion) {
    camiones.push_back(camion);
}

void Venta::agregarAccesorio(Accesorio* accesorio) {
    accesorios.push_back(accesorio);
}

// Calcular total sin descuento
double Venta::calcularTotalSinDescuento() const {
    double total = 0;
    for (const auto& auto_ : autos) {
        total += auto_->calcularPrecio();
    }
    for (const auto& moto : motos) {
        total += moto->calcularPrecio();
    }
    for (const auto& camion : camiones) {
        total += camion->calcularPrecio();
    }
    for (const auto& accesorio : accesorios) {
        total += accesorio->calcularPrecio();
    }
    return total;
}

// Aplicar descuento según cantidad de vehículos
double Venta::aplicarDescuento(double total) const {
    int totalVehiculos = cantidadVehiculos();
    if (totalVehiculos > 10000) {
        return total * 0.90;  
    } else if (totalVehiculos >= 5000) {
        return total * 0.95;  
    } else if (totalVehiculos >= 1000) {
        return total * 0.97;  
    } else {    
        return total * 0.99;  
    }
}

int Venta::cantidadVehiculos() const {
    return autos.size() + motos.size() + camiones.size();
}

// Total de clientes
int Venta::cantidadClientes() const {
    return clientes.size();
}


