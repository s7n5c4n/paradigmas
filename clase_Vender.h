#pragma once
#include <vector>
#include "Auto.h"
#include "Moto.h"
#include "Camion.h"

class Venta {
private:
    std::vector<Auto> autos;
    std::vector<Moto> motos;
    std::vector<Camion> camiones;
    int cantidadAutos;  
public:
    Venta() : cantidadAutos(0) {}
    void agregarAuto(Auto auto) {
        autos.push_back(auto);
        cantidadAutos++;
    }
    void agregarMoto(Moto* moto) {
        motos.pushback(moto);
    }
    void agregarCamion(Camion* camion) {
        camiones.push_back(camion);
    }
    double calcularTotal() const {
        double total = 0;
        for (const auto& auto : autos) {
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
};