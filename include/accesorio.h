#ifndef ACCESORIO_H
#define ACCESORIO_H
#include <iostream>
using namespace std;

class Accesorio{
public:
    string tipo;
    string nombre;
    int precio;
    Accesorio(string, string, int);
    ~Accesorio();
    void mostrarAccesorio();
};

#endif