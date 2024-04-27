#include <iostream>
using namespace std;

const int SIZE = 3;
const int NUM_MATRICES = 2;

int getIndex(int row, int col, int matrix) {
    return matrix * SIZE * SIZE + row * SIZE + col;
}

void multiplyMatrices(int *matrices, int *result) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                result[getIndex(i, j, 0)] += matrices[getIndex(i, k, 0)] * matrices[getIndex(k, j, 1)];
            }
        }
    }
}

void printMatrix(int *mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << mat[getIndex(i, j, 0)] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrices[NUM_MATRICES * SIZE * SIZE] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,

        9, 8, 7,
        6, 5, 4,
        3, 2, 1
    };

    int result[SIZE * SIZE] = {0};

    multiplyMatrices(matrices, result);

    cout << "Matriz 1:" << endl;
    printMatrix(matrices);

    cout << "Matriz 2:" << endl;
    printMatrix(matrices + SIZE * SIZE);

    cout << "Resultado de la multiplicación:" << endl;
    printMatrix(result);

    return 0;
}
