#include <iostream>
using namespace std;

const int SIZE = 3;
const int NUM_MATRICES = 2;

int* getElement(int *matrices, int row, int col, int matrix) {
    return matrices + matrix * SIZE * SIZE + row * SIZE + col;
}

void multiplyMatrices(int *matrices, int *result) {
    int *m = matrices;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int sum = 0;
            int *m1_temp = m;
            int *m2_temp = matrices + SIZE * SIZE + j;
            for (int k = 0; k < SIZE; ++k) {
                sum += (*m1_temp) * (*m2_temp);
                m1_temp++;
                m2_temp += SIZE;
            }
            *(result + i * SIZE + j) = sum;
        }
        m += SIZE;
    }
}

void printMatrix(int *mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << *getElement(mat, i, j, 0) << " ";
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
