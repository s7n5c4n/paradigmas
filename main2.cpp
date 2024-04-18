#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include "include/lista_enlazada.h"
#include "include/venta.h"
#include "include/GestorVenta.h"
#include <iostream>

using namespace std;

int main() {
    Vehiculo *Autos[5];
    Vehiculo *Motos[5];
    Vehiculo *Camiones[5];

    GestorVenta gestor;

    int opcion;

    //Autos
    Autos[0] = new Auto("Toyota", 19000, 4, 2002);
    Autos[1] = new Auto("Hyundai", 16000, 4, 2020);
    Autos[2] = new Auto("Susuki", 12000, 4, 2014);

    gestor.insertarAlInicio(new Venta("21518123-5", "cristopher", "auto", 100000, 10000, Autos[0]));
    gestor.imprimirLista();

    return 0;
}