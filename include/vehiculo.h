#include <vector>
#include <string>

using namespace std;

class Vehiculo {
private:
    struct Accesorio {
        string nombre;
        int precio;

        Accesorio(const string& nombre, int precio) : nombre(nombre), precio(precio) {}
    };

    vector<Accesorio> accesorios;

public:
    string marca;
    int precio;
    int cantidadRuedas;
    bool controlRemoto;
    int yearFabricacion;

    Vehiculo(int cantidadRuedas, string marca, bool controlRemoto, int yearFabricacion, int precio);
    virtual ~Vehiculo();

    void agregarAccesorio(const string& nombre, int precio);
    void mostrarAccesorios() const;
    Accesorio obtenerAccesorio(int indice) const;

    virtual void agregarAccesorios() = 0;
    virtual void mostrarDetalles() const = 0;
};

