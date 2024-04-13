#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}

int inversoMultiplicativo(int a, int n) {
    int m0 = n, tmp, q;
    int u0 = 0, u1 = 1;

    if (mcd(a, n) != 1) {
        cout << "No existe inverso multiplicativo para " << a << " mod " << n << endl;
        return -1;
    }

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

void encriptarArchivo(const string& archivoEntrada, const string& archivoSalida, int a, int b) {
    ifstream entrada(archivoEntrada);
    ofstream salida(archivoSalida);

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return;
    }

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    char caracter;
    while (entrada.get(caracter)) {
        int valorOriginal = static_cast<unsigned char>(caracter);
        int valorEncriptado = (a * valorOriginal + b) % 256;
        salida << static_cast<char>(valorEncriptado);
    }

    entrada.close();
    salida.close();
}

void desencriptarArchivo(const string& archivoEncriptado, const string& archivoDesencriptado, int a, int b) {
    int inverso_a = inversoMultiplicativo(a, b);

    if (inverso_a == -1) {
        cout << "No se puede calcular el inverso multiplicativo de 'a'." << endl;
        return;
    }

    ifstream entrada(archivoEncriptado);
    ofstream salida(archivoDesencriptado);

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo encriptado." << endl;
        return;
    }

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo desencriptado." << endl;
        return;
    }

    char caracter;
    while (entrada.get(caracter)) {
        int valorEncriptado = static_cast<unsigned char>(caracter);
        int valorOriginal = (inverso_a * (valorEncriptado)) % 256;
        salida << static_cast<char>(valorOriginal);
    }

    entrada.close();
    salida.close();
}


int main() {
    int a, b;
    string archivoEntrada, archivoEncriptado, archivoDesencriptado;

    cout << "Ingrese la clave a: ";
    cin >> a;
    cout << "Ingrese la clave b (mod): ";
    cin >> b;

    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> archivoEntrada;

    archivoEncriptado = archivoEntrada + "_encriptado.txt";
    archivoDesencriptado = archivoEntrada + "_desencriptado.txt";

    encriptarArchivo(archivoEntrada, archivoEncriptado, a, b);
    cout << "Archivo encriptado creado: " << archivoEncriptado << endl;

    desencriptarArchivo(archivoEncriptado, archivoDesencriptado, a, b);
    cout << "Archivo desencriptado creado: " << archivoDesencriptado << endl;

    return 0;
}
