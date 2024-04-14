#pragma once
#include <vector>
#include "auto.h"
#include "moto.h"
#include "camion.h"
#include "accesorio.h"

class Venta {
private:
    std::vector<Auto*> autos;
    std::vector<Moto*> motos;
    std::vector<Camion*> camiones;
    std::vector<Accesorio*> accesorios;
    int cantidadAutos;

public:
    Venta() : cantidadAutos(0) {}

    void agregarAuto(Auto* auto_) {
        autos.push_back(auto_);
        cantidadAutos++;
    }

    void agregarMoto(Moto* moto) {
        motos.push_back(moto);
    }

    void agregarCamion(Camion* camion) {
        camiones.push_back(camion);
    }

    void agregarAccesorio(Accesorio* accesorio) {
        accesorios.push_back(accesorio);
    }

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
        for (const auto& accesorio : accesorios) {
            total += accesorio->calcularPrecio();
        }
        return total;
    }

    double aplicarDescuento(double total) const {
        if (totalVehiculos() > 10000) {
            return total * 0.90;  
        } else if (totalVehiculos() >= 5000) {
            return total * 0.95;  
        } else if (totalVehiculos() >= 1000) {
            return total * 0.97;  
        } else {
            return total * 0.99;  
        }
    }
    int totalVehiculos() const {
        return autos.size() + motos.size() + camiones.size();
    }
};