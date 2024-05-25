#include <iostream>

using namespace std;

void fillMatrix(int* matrix, int fil, int cols) {
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Ingrese el elemento [" << i << "][" << j << "]: ";
            cin >> *(matrix + i * cols + j);
        }
    }
}

void printMatrix(const int* matrix, int fil, int cols) {
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(matrix + i * cols + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int filA, colsA, filB, colsB;

    cout << "Ingrese el numero de filas de la matriz A: ";
    cin >> filA;
    cout << "Ingrese el numero de columnas de la matriz A: ";
    cin >> colsA;
    cout << "Ingrese el numero de filas de la matriz B: ";
    cin >> filB;
    cout << "Ingrese el numero de columnas de la matriz B: ";
    cin >> colsB;

    int* A = new int[filA * colsA];
    int* B = new int[filB * colsB];
    int* C = new int[filA * colsB];

    for (int i = 0; i < filA * colsB; ++i) {
        C[i] = 0;
    }

    cout << "Rellene la matriz A (" << filA << "x" << colsA << "):" << endl;
    fillMatrix(A, filA, colsA);
    cout << "Rellene la matriz B (" << filB << "x" << colsB << "):" << endl;
    fillMatrix(B, filB, colsB);

    for (int i = 0; i < filA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                *(C + i * colsB + j) += *(A + i * colsA + k) * *(B + k * colsB + j);
            }
        }
    }

    cout << "Matriz A (" << filA << "x" << colsA << "):" << endl;
    printMatrix(A, filA, colsA);

    cout << "Matriz B (" << filB << "x" << colsB << "):" << endl;
    printMatrix(B, filB, colsB);

    cout << "Matriz C (" << filA << "x" << colsB << "):" << endl;
    printMatrix(C, filA, colsB);

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
