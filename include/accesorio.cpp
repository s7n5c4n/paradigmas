#include "accesorio.h"
#include <iostream>

using namespace std;

Accesorio::Accesorio(string _tipo, string _nombre, int _precio){
    tipo = _tipo;
    nombre = _nombre;
    precio = _precio;
    cout << "Accesorio creado" << endl;
}

Accesorio::~Accesorio(){}

void Accesorio::mostrarAccesorio(){
    cout << nombre << ": "<< precio <<endl;
}

