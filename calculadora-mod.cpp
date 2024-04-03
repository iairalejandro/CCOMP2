#include <iostream>

using namespace std;

// Función para calcular la suma de dos números módulo n
int sumaModulo(int a, int b, int n) {
    return (a + b) % n;
}

// Función para calcular la resta de dos números módulo n
int restaModulo(int a, int b, int n) {
    return ((a - b) % n + n) % n;
}

int main() {
    int opcion;
    int a, b, n;

    do {
        cout << "Seleccione una operacion:" << endl;
        cout << "1. Suma de modulos" << endl;
        cout << "2. Resta de modulos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el primer numero: ";
                cin >> a;
                cout << "Ingrese el segundo numero: ";
                cin >> b;
                cout << "Ingrese el módulo: ";
                cin >> n;
                cout << "El resultado de la suma es: " << sumaModulo(a, b, n) << endl;
                break;
            case 2:
                cout << "Ingrese el primer numero: ";
                cin >> a;
                cout << "Ingrese el segundo numero: ";
                cin >> b;
                cout << "Ingrese el modulo: ";
                cin >> n;
                cout << "El resultado de la resta es: " << restaModulo(a, b, n) << endl;
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << endl;
    } while (opcion != 0);

    return 0;
}
