#include "include/vehiculo.h"
#include "include/auto.h"
#include "include/camion.h"
#include "include/moto.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    Camion auto1("Hyundai", 20000, 4, true, 2003);
    auto1.agregarAccesorio("pedales", 30000);
    cout << "La marca es: " << auto1.marca << endl;
    cout << "El accesorio es: " << auto1.obtenerAccesorio(0).nombre << endl;
    cout << "El precio es: " << auto1.obtenerAccesorio(0).precio << endl;
    auto1.mostrarDetalles();
    return 0;
}

