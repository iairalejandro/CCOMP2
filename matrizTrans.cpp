#include <iostream>
#include <string>
using namespace std;

void printMatrix(const int* matrix, int fil, int cols) {
    cout << "Matriz Original:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(matrix + i * cols + j) << " ";
        }
        cout << endl;
    }
}

void TranMatriz(int* matrix, int fil, int cols) {
    int* transpuesta = new int[cols * fil];

    // Calculando la transpuesta
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(transpuesta + j * fil + i) = *(matrix + i * cols + j);
        }
    }

    // Mostrando la transpuesta
    cout << "Matriz Transpuesta:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < fil; ++j) {
            cout << *(transpuesta + i * fil + j) << " ";
        }
        cout << endl;
    }

    delete[] transpuesta;
}

int main() {
    int fil, cols;

    cout << "Ingrese el número de filas: ";
    cin >> fil;
    cout << "Ingrese el número de columnas: ";
    cin >> cols;

    int* matrix = new int[fil * cols];

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(matrix + i * cols + j);
        }
    }

    // Mostrar la matriz original
    printMatrix(matrix, fil, cols);

    // Calcular y mostrar la matriz transpuesta
    TranMatriz(matrix, fil, cols);

    delete[] matrix;

    return 0;
}
