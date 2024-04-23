#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include "include/lista_enlazada.h"
#include "include/ventaVehiculos.h"
#include "include/ventaAccesorios.h"
#include "include/GestorVenta.h"
#include "include/accesorio.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void LeerInventarioAccesorios(vector<Accesorio> & autos, vector<Accesorio> & motos, vector<Accesorio> & camiones) {
    ifstream archivo("accesorios.txt");
    
    if (archivo.is_open()) {
        string linea;
        
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            
            string tipo, marca;
            int precio;
            
            getline(ss, tipo, ',');
            getline(ss, marca, ',');
            ss >> precio;
            if (tipo == "auto"){
                autos.push_back(Accesorio(tipo, marca, precio));
            }else if (tipo == "moto")
            {
                motos.push_back(Accesorio(tipo, marca, precio));
            }else if (tipo == "camion")
            {
                camiones.push_back(Accesorio(tipo, marca, precio));
            };
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main() {
    Vehiculo *Autos[5];
    Vehiculo *Motos[5];
    Vehiculo *Camiones[5];

    vector<Accesorio> accesoriosAuto;
    vector<Accesorio> accesoriosMoto;
    vector<Accesorio> accesoriosCamion;

    LeerInventarioAccesorios(accesoriosAuto, accesoriosMoto, accesoriosCamion);

    cout << accesoriosAuto.size() << endl;

    for (int i = 0; i < accesoriosAuto.size(); i++) {
        cout << i+1 << ". " << accesoriosAuto[i].nombre << ": " << accesoriosAuto[i].precio << endl;
    }

    GestorVenta gestor;

    int opcion;

    //Autos
    Autos[0] = new Auto("Toyota", 19000, 4, 2002);
    Autos[1] = new Auto("Hyundai", 16000, 4, 2020);
    Autos[2] = new Auto("Susuki", 12000, 4, 2014);

    gestor.insertarAlInicio(new VentaVehiculo("21518123-5", "cristopher", "auto", 100000, 10000, Autos[0], accesoriosMoto));
    gestor.imprimirLista();

    new VentaAccesorios("21518123-5", "cristopher", "auto", accesoriosAuto);

    return 0;
}