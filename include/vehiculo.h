#include <iostream>
#include <vector>

using namespace std;

class Vehiculo{
private:
    int cantidadRuedas;
    bool controlRemoto;
    int yearFabricacion;
    struct Accesorio {
        string nombre;
        int precio;

        Accesorio(const string& nombre, int precio) : nombre(nombre), precio(precio) {}
    };

    vector<Accesorio> accesorios;

public:
    string marca;
    int precio;

    Vehiculo(string, int, int, bool, int);

    void agregarAccesorio(const string& nombre, int precio);
    Accesorio obtenerAccesorio(int indice);
    virtual void mostrarAccesorios();
    virtual void mostrarDetalles();
};
