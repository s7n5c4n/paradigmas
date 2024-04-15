#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){

    Vehiculo *inventario[17];

    //Autos
    inventario[0] = new Auto("Toyota", 19000, 4, true, 2002);
    inventario[1] = new Auto("Hyundai", 16000, 4, true, 2020);
    inventario[2] = new Auto("Susuki", 12000, 4, true, 2014);
    inventario[3] = new Auto("Ford", 17000, 4, true, 2016);
    inventario[4] = new Auto("Chevrolet", 18000, 4, true, 2018);
    inventario[5] = new Auto("Honda", 21000, 4, true, 2023);
    //Motos
    inventario[6] = new Moto("Yamaha", 14000, 4, true, 2002);
    inventario[7] = new Moto("Susuki", 8000, 4, true, 2024);
    inventario[8] = new Moto("Honda", 15000, 4, true, 2014);
    inventario[9] = new Moto("KTM", 5000, 4, true, 2011);
    inventario[10] = new Moto("BWM", 18000, 4, true, 2010);
    inventario[11] = new Moto("Kawasaki", 13000, 4, true, 2023);
    //Camiones
    inventario[12] = new Camion("Volvo", 100000, 4, true, 2002);
    inventario[13] = new Camion("Iveco", 85000, 4, true, 2024);
    inventario[14] = new Camion("Mercedes", 110000, 4, true, 2014);
    inventario[15] = new Camion("Isuzu", 70000, 4, true, 2011);
    inventario[16] = new Camion("MAN", 105000, 4, true, 2010);
    inventario[17] = new Camion("Scania", 95000, 4, true, 2023);

    
    return 0;
}

