#include <iostream>
using namespace std;


int binarySearch(int *array, int size, int target) {
    int izq = 0;
    int der = size - 1;

    while (izq <= der) {
        int mid = izq + (der - izq) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] < target) {
            izq = mid + 1;
        }

        else {
            der = mid - 1;
        }
    }
    return -1;
}

int main() {
    int array[] = {1, 3, 5, 7, 9, 11, 13, 14, 17, 19};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 4;

    int result = binarySearch(array, size, target);
    if (result != -1) {
        cout << "Elemento encontrado en el lugar: " << result << " del arreglo" << endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }

    return 0;
}
