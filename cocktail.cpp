#include <iostream>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cocktailSort(int *arr, int n) {
    bool swapped = true;
    int *start = arr;
    int *end = arr + n - 1;

    while (swapped) {
        swapped = false;

        for (int *i = start; i < end; ++i) {
            if (*i > *(i + 1)) {
                swap(i, i + 1);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
        --end;

        for (int *i = end - 1; i >= start; --i) {
            if (*i > *(i + 1)) {
                swap(i, i + 1);
                swapped = true;
            }
        }
        ++start;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {5, 1, 7, 13, 9, 0, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    printArray(arr, n);

    cocktailSort(arr, n);

    std::cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
