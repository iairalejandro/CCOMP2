#include <iostream>
#include <string>
using namespace std;

void printMatriz(const int* mat, int fil, int cols) {
    cout << "\nMatriz Original:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(mat + i * cols + j) << " ";
        }
        cout << endl;
    }
}

void TranMatriz(int* mat, int fil, int cols) {
    int* transpuesta = new int[cols * fil];

    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(transpuesta + j * fil + i) = *(mat + i * cols + j);
        }
    }

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

    cout << "Ingrese el numero de filas: ";
    cin >> fil;
    cout << "Ingrese el numero de columnas: ";
    cin >> cols;

    int* mat = new int[fil * cols];

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(mat + i * cols + j);
        }
    }

    printMatriz(mat, fil, cols);
    TranMatriz(mat, fil, cols);
    delete[] mat;
    return 0;
}
