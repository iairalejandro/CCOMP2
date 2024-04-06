#include <iostream>

using namespace std;

int sumaModulo(int a, int b, int n) {
    return (a + b) % n;
}

int restaModulo(int a, int b, int n) {
    return ((a - b) % n + n) % n;
}

int multiModulo(int a, int b, int n) {
    return (a * b) % n;
}

int inversoMultiplicativo(int a, int n) {
    int m0 = n, tmp, q;
    int u0 = 0, u1 = 1;

    if (n == 1)
        return 1;

    while (a > 1) {
        q = a / n;
        tmp = n;
        n = a % n;
        a = tmp;
        tmp = u0;
        u0 = u1 - q * u0;
        u1 = tmp;
    }

    if (u1 < 0)
        u1 += m0;

    return u1;
}

int main() {
    int opcion;
    int a, b, n;

    do {
        cout << "Seleccione una operacion:" << endl;
        cout << "1. Suma de modulos" << endl;
        cout << "2. Resta de modulos" << endl;
        cout << "3. Multiplicacion de modulos" << endl;
        cout << "4. Inverso multiplicativo" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el modulo: ";
                cin >> n;
                cout << "Ingrese el primer numero: ";
                cin >> a;
                cout << "Ingrese el segundo numero: ";
                cin >> b;
                cout << "El resultado de la suma es: " << sumaModulo(a, b, n) << " mod " << n << endl;
                break;
            case 2:
                cout << "Ingrese el modulo: ";
                cin >> n;
                cout << "Ingrese el primer numero: ";
                cin >> a;
                cout << "Ingrese el segundo numero: ";
                cin >> b;
                cout << "El resultado de la resta es: " << restaModulo(a, b, n) << " mod " << n << endl;
                break;
            case 3:
                cout << "Ingrese el modulo: ";
                cin >> n;
                cout << "Ingrese el primer numero: ";
                cin >> a;
                cout << "Ingrese el segundo numero: ";
                cin >> b;
                cout << "El resultado de la multiplicacion es: " << multiModulo(a, b, n) << " mod " << n << endl;
                break;
            case 4:
                cout << "Ingrese el numero: ";
                cin >> a;
                cout << "Ingrese el modulo: ";
                cin >> n;
                cout << "El inverso multiplicativo de " << a << " mod " << n << " es: " << inversoMultiplicativo(a, n) << " mod " << n << endl;
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        cout << endl;
    } while (opcion != 0);

    return 0;
}
