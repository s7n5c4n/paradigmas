#include "Venta.h" 

//liberar memoria
Venta::~Venta() {
    for (auto& auto_ : autos) {
        delete auto_;
    }
    for (auto& moto : motos) {
        delete moto;
    }
    for (auto& camion : camiones) {
        delete camion;
    }
    for (auto& accesorio : accesorios) {
        delete accesorio;
    }
}

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

double Venta::aplicarDescuento(double total) const {
    int total_vehiculos = totalVehiculos();
    if (total_vehiculos > 10000) {
        return total * 0.90;  
    } else if (total_vehiculos >= 5000) {
        return total * 0.95;  
    } else if (total_vehiculos >= 1000) {
        return total * 0.97;  
    } else {    
        return total * 0.99;  
    }
}

int Venta::totalVehiculos() const {
    return autos.size() + motos.size() + camiones.size();
}

