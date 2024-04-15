#include "include/vehiculo.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    Vehiculo moto("Hyundai", 20000, 2, true, 2003);
    moto.agregarAccesorio("pedales", 30000);
    cout << "La marca es: " << moto.marca << endl;
    cout << "El accesorio es: " << moto.obtenerAccesorio(0).nombre << endl;
    cout << "El precio es: " << moto.obtenerAccesorio(0).precio << endl;
    return 0;
}

