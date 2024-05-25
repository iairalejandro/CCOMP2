#include <iostream>
using namespace std;

void printMatriz(int** mat, int fil, int cols) {
    cout << "\nMatriz Original:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void TranMatriz(int** mat, int fil, int cols) {
    // Crear la matriz transpuesta
    int** transpuesta = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        transpuesta[i] = new int[fil];
    }

    // Calculando la transpuesta
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpuesta[j][i] = mat[i][j];
        }
    }

    // Mostrando la transpuesta
    cout << "Matriz Transpuesta:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < fil; ++j) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria de la matriz transpuesta
    for (int i = 0; i < cols; ++i) {
        delete[] transpuesta[i];
    }
    delete[] transpuesta;
}

int main() {
    int fil, cols;

    cout << "Ingrese el numero de filas: ";
    cin >> fil;
    cout << "Ingrese el numero de columnas: ";
    cin >> cols;

    // Crear la matriz original
    int** mat = new int*[fil];
    for (int i = 0; i < fil; ++i) {
        mat[i] = new int[cols];
    }

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat[i][j];
        }
    }

    // Mostrar la matriz original
    printMatriz(mat, fil, cols);

    // Calcular y mostrar la matriz transpuesta
    TranMatriz(mat, fil, cols);

    // Liberar la memoria de la matriz original
    for (int i = 0; i < fil; ++i) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
