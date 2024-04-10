#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Definición de la clase Vehiculo
class Vehiculo {
public:
    virtual void mostrarCaracteristicas() const = 0;
    virtual int calcularPrecio(int cantidad) const = 0;
    virtual string obtenerTipo() const = 0;
};

// Definición de las clases derivadas Auto, Moto y Camion
class Auto : public Vehiculo {
public:
    Auto(int _precioBase, int _precioMarca) : precioBase(_precioBase), precioMarca(_precioMarca) {}

    void mostrarCaracteristicas() const override {
        cout << "Auto: Cantidad de ruedas: 4, Control remoto: Sí, Año de fabricación: 2024" << endl;
    }

    int calcularPrecio(int cantidad) const override {
        int precioTotal = precioBase + precioMarca;
        return aplicarDescuento(precioTotal, cantidad);
    }

    string obtenerTipo() const override {
        return "Auto";
    }

private:
    int precioBase;
    int precioMarca;

    int aplicarDescuento(int precio, int cantidad) const {
        if (cantidad > 10000) {
            return precio * 0.9; // Descuento del 10%
        } else if (cantidad >= 5000 && cantidad <= 10000) {
            return precio * 0.95; // Descuento del 5%
        } else if (cantidad >= 1000 && cantidad <= 4999) {
            return precio * 0.97; // Descuento del 3%
        } else {
            return precio * 0.99; // Descuento del 1%
        }
    }
};

class Moto : public Vehiculo {
public:
    Moto(int _precioBase, int _precioMarca) : precioBase(_precioBase), precioMarca(_precioMarca) {}

    void mostrarCaracteristicas() const override {
        cout << "Moto: Cantidad de ruedas: 2, Control remoto: No, Año de fabricación: 2024" << endl;
    }

    int calcularPrecio(int cantidad) const override {
        int precioTotal = precioBase + precioMarca;
        return aplicarDescuento(precioTotal, cantidad);
    }

    string obtenerTipo() const override {
        return "Moto";
    }

private:
    int precioBase;
    int precioMarca;

    int aplicarDescuento(int precio, int cantidad) const {
        if (cantidad > 10000) {
            return precio * 0.9; // Descuento del 10%
        } else if (cantidad >= 5000 && cantidad <= 10000) {
            return precio * 0.95; // Descuento del 5%
        } else if (cantidad >= 1000 && cantidad <= 4999) {
            return precio * 0.97; // Descuento del 3%
        } else {
            return precio * 0.99; // Descuento del 1%
        }
    }
};

class Camion : public Vehiculo {
public:
    Camion(int _precioBase, int _precioMarca) : precioBase(_precioBase), precioMarca(_precioMarca) {}

    void mostrarCaracteristicas() const override {
        cout << "Camion: Cantidad de ruedas: 6, Control remoto: Sí, Año de fabricación: 2024" << endl;
    }

    int calcularPrecio(int cantidad) const override {
        int precioTotal = precioBase + precioMarca;
        return aplicarDescuento(precioTotal, cantidad);
    }

    string obtenerTipo() const override {
        return "Camion";
    }

private:
    int precioBase;
    int precioMarca;

    int aplicarDescuento(int precio, int cantidad) const {
        if (cantidad > 10000) {
            return precio * 0.9; // Descuento del 10%
        } else if (cantidad >= 5000 && cantidad <= 10000) {
            return precio * 0.95; // Descuento del 5%
        } else if (cantidad >= 1000 && cantidad <= 4999) {
            return precio * 0.97; // Descuento del 3%
        } else {
            return precio * 0.99; // Descuento del 1%
        }
    }
};

// Definición de la clase Accesorio
class Accesorio {
public:
    Accesorio(string _nombre, int _precio) : nombre(_nombre), precio(_precio) {}

    void mostrar() const {
        cout << "Accesorio: " << nombre << ", Precio: $" << precio << endl;
    }

    int getPrecio() const {
        return precio;
    }
    
    string getNombre() const {
        return nombre;
    }

private:
    string nombre;
    int precio;
};

// Definición de la clase Cliente
class Cliente {
public:
    Cliente(string _nombre, string _rut) : nombre(_nombre), rut(_rut) {}

    string getNombre() const {
        return nombre;
    }

    string getRut() const {
        return rut;
    }

private:
    string nombre;
    string rut;
};

// Definición de la clase Venta
class Venta {
public:
    Venta(Cliente _cliente, int _cantidadVehiculos, int _cantidadAccesorios, int _totalVehiculos, int _totalAccesorios, int _totalVenta)
        : cliente(_cliente), cantidadVehiculos(_cantidadVehiculos), cantidadAccesorios(_cantidadAccesorios), totalVehiculos(_totalVehiculos),
          totalAccesorios(_totalAccesorios), totalVenta(_totalVenta) {}

    void mostrar() const {
        cout << "CLIENTE: " << cliente.getNombre() << endl;
        cout << "RUT: " << cliente.getRut() << endl;
        cout << "CANTIDAD (Vehículos Total): " << cantidadVehiculos << endl;
        cout << "CNTIDAD (Accesorios Total): " << cantidadAccesorios << endl;
        cout << "Total precio Accesorios: $" << getTotalAccesorios() << endl;
        cout << "TOTAL precio Vehículos: $" << totalVehiculos << endl;
        cout << "TOTAL con descuento 3%: $" << totalVenta << endl;
        cout << "TOTAL GENERAL: $" << getTotalGeneral() << endl;
    }

    Cliente getCliente() const {
        return cliente;
    }

    int getCantidadVehiculos() const {
        return cantidadVehiculos;
    }

    int getCantidadAccesorios() const {
        return cantidadAccesorios;
    }

    int getTotalVenta() const {
        return totalVenta;
    }

    int getTotalAccesorios() const {
        return totalAccesorios;
    }

    int getTotalGeneral() const {
        return totalVenta + totalAccesorios;
    }

private:
    Cliente cliente;
    int cantidadVehiculos;
    int cantidadAccesorios;
    int totalVehiculos;
    int totalAccesorios;
    int totalVenta;
};


// Clase para manejar las operaciones de venta
class ManejadorVentas {
public:
    void venderVehiculos(vector<Vehiculo*>& inventario, Cliente cliente, int cantidad) {
        int totalVehiculos = 0;
        int totalVenta = 0;

        for (auto vehiculo : inventario) {
            totalVehiculos += cantidad;
            totalVenta += vehiculo->calcularPrecio(cantidad);
        }

        ventas.push_back(Venta(cliente, cantidad, 0, totalVenta, 0, totalVenta * 0.97));
    }

    void venderAccesorios(vector<Accesorio>& inventario, Cliente cliente, int cantidad) {
        int totalAccesorios = 0;

        for (auto& accesorio : inventario) {
            totalAccesorios += accesorio.getPrecio() * cantidad;
        }

        ventas.back().mostrar();

        ventas.back() = Venta(cliente, 0, cantidad, 0, totalAccesorios, totalAccesorios * 0.97);
    }

    void mostrarVentas() {
        for (auto& venta : ventas) {
            venta.mostrar();
        }
    }

    Cliente clienteMasCompras() {
        int maxCompras = -1;
        Cliente clienteMasCompras("", "");

        for (auto& venta : ventas) {
            if (venta.getCantidadVehiculos() > maxCompras) {
                maxCompras = venta.getCantidadVehiculos();
                clienteMasCompras = venta.getCliente();
            }
        }

        return clienteMasCompras;
    }

    Cliente clienteMasAccesorios() {
        int maxAccesorios = -1;
        Cliente clienteMasAccesorios("", "");

        for (auto& venta : ventas) {
            if (venta.getCantidadAccesorios() > maxAccesorios) {
                maxAccesorios = venta.getCantidadAccesorios();
                clienteMasAccesorios = venta.getCliente();
            }
        }

        return clienteMasAccesorios;
    }

    int cantidadTotalVehiculos() {
        int total = 0;

        for (auto& venta : ventas) {
            total += venta.getCantidadVehiculos();
        }

        return total;
    }

    double promedioVentas() {
        int totalClientes = ventas.size();
        int totalVentas = 0;

        for (auto& venta : ventas) {
            totalVentas += venta.getTotalVenta();
        }

        if (totalClientes != 0) {
            return static_cast<double>(totalVentas) / totalClientes;
        } else {
            return 0.0;
        }
    }

    void almacenarVentas() {
        ofstream archivo("ventas.txt");
        if (archivo.is_open()) {
            for (auto& venta : ventas) {
                archivo << "CLIENTE: " << venta.getCliente().getNombre() << endl;
                archivo << "RUT: " << venta.getCliente().getRut() << endl;
                archivo << "CANTIDAD (Vehículos Total): " << venta.getCantidadVehiculos() << endl;
                archivo << "CNTIDAD (Accesorios Total): " << venta.getCantidadAccesorios() << endl;
                archivo << "Total precio Accesorios: $" << venta.getTotalVenta() - venta.getTotalAccesorios() << endl;
                archivo << "TOTAL precio Vehículos: $" << venta.getTotalAccesorios() << endl;
                archivo << "TOTAL con descuento 3%: $" << venta.getTotalVenta() << endl;
                archivo << "TOTAL GENERAL: $" << venta.getTotalVenta() + venta.getTotalAccesorios() << endl << endl;
            }
            archivo.close();
            cout << "Las ventas se han almacenado correctamente en el archivo 'ventas.txt'" << endl;
        } else {
            cout << "Error al abrir el archivo para almacenar las ventas." << endl;
        }
    }

private:
    vector<Venta> ventas;
};

// Función principal
int main() {
    // Variables y contenedores necesarios
    vector<Vehiculo*> inventarioVehiculos;
    vector<Accesorio> inventarioAccesorios;
    ManejadorVentas manejador;

    // Lógica del menú de opciones
    int opcion;
    do {
        cout << "Menu de opciones:" << endl;
        cout << "1. Venta de vehiculos" << endl;
        cout << "2. Venta de accesorios" << endl;
        cout << "3. Promedio de ventas" << endl;
        cout << "4. Cantidad total de vehículos comprados" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Lógica para realizar una venta de vehículos
                string nombreCliente, rutCliente;
                int cantidadVehiculos;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese RUT del cliente: ";
                cin >> rutCliente;
                cout << "Ingrese cantidad de vehículos a comprar: ";
                cin >> cantidadVehiculos;

                Cliente cliente(nombreCliente, rutCliente);
                manejador.venderVehiculos(inventarioVehiculos, cliente, cantidadVehiculos);
                break;
            }
            case 2: {
                // Lógica para realizar una venta de accesorios
                string nombreCliente, rutCliente, nombreAccesorio;
                int cantidadAccesorios;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese RUT del cliente: ";
                cin >> rutCliente;
                cout << "Ingrese nombre del accesorio: ";
                cin >> nombreAccesorio;
                cout << "Ingrese cantidad de accesorios a comprar: ";
                cin >> cantidadAccesorios;

                Cliente cliente(nombreCliente, rutCliente);
                Accesorio accesorio(nombreAccesorio, 1000); // Precio de ejemplo, ajustar según sea necesario
                inventarioAccesorios.push_back(accesorio);
                manejador.venderAccesorios(inventarioAccesorios, cliente, cantidadAccesorios);
                break;
            }
            case 3: {
                // Lógica para mostrar promedio de ventas
                double promedio = manejador.promedioVentas();
                cout << "Promedio de ventas: $" << promedio << endl;
                break;
            }
            case 4: {
                // Lógica para mostrar cantidad total de vehículos comprados
                int total = manejador.cantidadTotalVehiculos();
                cout << "Cantidad total de vehículos comprados: " << total << endl;
                break;
            }
            case 5:
                // Lógica para salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor ingrese un numero entre 1 y 5." << endl;
        }
    } while (opcion != 5);

    // Liberar memoria de los vehículos
    for (auto vehiculo : inventarioVehiculos) {
        delete vehiculo;
    }

    // Almacenar ventas antes de salir
    manejador.almacenarVentas();

    return 0;
}

