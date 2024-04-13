#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
    public:
        int cantidadRuedas;
        string marca;
        bool controlRemoto;
        int yearFabricacion;
        Vehiculo(int, string, bool, int);
        ~Vehiculo();
};

