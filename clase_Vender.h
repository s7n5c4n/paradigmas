#pragma once
#include <vector>
#include "auto.h"
#include "moto.h"
#include "camion.h"

class Venta {
private:
    struct Cliente {
        std::string nombre;
        int rut;
        Cliente(const std::string& nombre, int rut) : nombre(nombre), rut(rut) {}
    };

    std::vector<Cliente> clientes;
    std::vector<Auto*> autos;
    std::vector<Moto*> motos;
    std::vector<Camion*> camiones;

public:
    Venta() {}

    void agregarCliente(const std::string& nombre, int rut) {
        clientes.emplace_back(nombre, rut);
    }
    void agregarAuto(Auto* auto_) {
        autos.push_back(auto_);
    }
    void agregarMoto(Moto* moto) {
        motos.push_back(moto);
    }
    void agregarCamion(Camion* camion) {
        camiones.push_back(camion);
    }

    // Método para obtener el precio de un accesorio asociado a un vehículo
    double obtenerPrecioAccesorio(int tipoVehiculo, int indiceVehiculo, int indiceAccesorio) const;

    double calcularTotalSinDescuento() const {
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
        return total;
    }

    double aplicarDescuento(double total) const {
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

    int cantidadVehiculos() const {
        return autos.size() + motos.size() + camiones.size();
    }

    int cantidadClientes() const {
        return clientes.size();
    }
};
