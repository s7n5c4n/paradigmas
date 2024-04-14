#include "Venta.h"

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
}

