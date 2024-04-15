#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Definición de clases
class Vehiculo {
protected:
    string marca;
    double precioBase;
public:
    Vehiculo(string _marca, double _precioBase) : marca(_marca), precioBase(_precioBase) {}

    virtual double calcularPrecio() = 0;
    string obtenerMarca() const { return marca; } // Función de acceso público para obtener la marca
};

class Auto : public Vehiculo {
private:
    string accesorio1;
    string accesorio2;
public:
    Auto(string _marca, double _precioBase, string _accesorio1, string _accesorio2) : Vehiculo(_marca, _precioBase), accesorio1(_accesorio1), accesorio2(_accesorio2) {}

    double calcularPrecio() override {
        return precioBase;
    }
};

class Moto : public Vehiculo {
private:
    string accesorio1;
    string accesorio2;
public:
    Moto(string _marca, double _precioBase, string _accesorio1, string _accesorio2) : Vehiculo(_marca, _precioBase), accesorio1(_accesorio1), accesorio2(_accesorio2) {}

    double calcularPrecio() override {
        return precioBase;
    }
};

class Camion : public Vehiculo {
private:
    string accesorio1;
    string accesorio2;
public:
    Camion(string _marca, double _precioBase, string _accesorio1, string _accesorio2) : Vehiculo(_marca, _precioBase), accesorio1(_accesorio1), accesorio2(_accesorio2) {}

    double calcularPrecio() override {
        return precioBase;
    }
};

class Cliente {
private:
    string rut;
    string nombre;
    int cantidadComprada;
public:
    Cliente(string _rut, string _nombre, int _cantidadComprada) : rut(_rut), nombre(_nombre), cantidadComprada(_cantidadComprada) {}

    int getCantidadComprada() const {
        return cantidadComprada;
    }

    string getRut() const {
        return rut;
    }
};

// Función para calcular el descuento
double calcularDescuento(int cantidadComprada) {
    if (cantidadComprada > 10000) {
        return 0.1;
    } else if (cantidadComprada >= 5000 && cantidadComprada <= 10000) {
        return 0.05;
    } else if (cantidadComprada >= 1000 && cantidadComprada <= 4999) {
        return 0.03;
    } else {
        return 0.01;
    }
}

// Función para realizar una venta
void realizarVenta(vector<Vehiculo*>& inventario, vector<Cliente*>& clientes) {
    string nombreCliente, rutCliente;
    int cantidadComprada;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;
    cout << "Ingrese el RUT del cliente: ";
    cin >> rutCliente;
    cout << "Ingrese la cantidad de vehiculos comprados: ";
    cin >> cantidadComprada;

    // Mostrar opciones de vehiculos disponibles
    cout << "Vehiculos disponibles:" << endl;
    for (int i = 0; i < inventario.size(); ++i) {
        cout << i + 1 << ". Marca: " << inventario[i]->obtenerMarca() << endl;
    }

    // Seleccionar vehiculo a comprar
    int opcion;
    cout << "Seleccione el vehiculo a comprar: ";
    cin >> opcion;
    if (opcion < 1 || opcion > inventario.size()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    // Calcular precio final con descuento
    double precioFinal = inventario[opcion - 1]->calcularPrecio() * (1 - calcularDescuento(cantidadComprada));

    // Guardar la venta
    clientes.push_back(new Cliente(rutCliente, nombreCliente, cantidadComprada));

    cout << "Venta realizada con exito. Precio final: $" << precioFinal << endl;
}

// Función para mostrar la cantidad total de vehiculos comprados
void mostrarCantidadTotalVehiculos(vector<Cliente*>& clientes) {
    int total = 0;
    for (auto cliente : clientes) {
        total += cliente->getCantidadComprada();
    }
    cout << "Cantidad total de vehiculos comprados: " << total << endl;
}

// Función para mostrar el promedio de ventas totales
void mostrarPromedioVentas(vector<Cliente*>& clientes) {
    double totalVentas = 0;
    for (auto cliente : clientes) {
        totalVentas += cliente->getCantidadComprada();
    }
    double promedio = totalVentas / clientes.size();
    cout << "Promedio de ventas totales: " << promedio << endl;
}

// Función para cargar el inventario desde un archivo
void cargarInventarioDesdeArchivo(vector<Vehiculo*>& inventario) {
    ifstream archivo("inventario.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de inventario." << endl;
        return;
    }

    string marca, tipo, accesorio1, accesorio2;
    double precioBase;
    while (archivo >> marca >> precioBase >> tipo >> accesorio1 >> accesorio2) {
        if (tipo == "Auto") {
            inventario.push_back(new Auto(marca, precioBase, accesorio1, accesorio2));
        } else if (tipo == "Moto") {
            inventario.push_back(new Moto(marca, precioBase, accesorio1, accesorio2));
        } else if (tipo == "Camion") {
            inventario.push_back(new Camion(marca, precioBase, accesorio1, accesorio2));
        }
    }

    archivo.close();
}

int main() {
    vector<Vehiculo*> inventario;
    vector<Cliente*> clientes;

    // Cargar inventario desde archivo
    cargarInventarioDesdeArchivo(inventario);

    int opcion;
    do {
        // Mostrar menu
        cout << "\n--- MENU ---" << endl;
        cout << "1. Venta de Vehiculos a clientes" << endl;
        cout << "2. Promedio de ventas" << endl;
        cout << "3. Cantidad de vehiculos comprados" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                realizarVenta(inventario, clientes);
                break;
            case 2:
                mostrarPromedioVentas(clientes);
                break;
            case 3:
                mostrarCantidadTotalVehiculos(clientes);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 4);

    // Liberar memoria
    for (auto vehiculo : inventario) {
        delete vehiculo;
    }
    for (auto cliente : clientes) {
        delete cliente;
    }

    return 0;
}

