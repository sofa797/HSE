#include <stdio.h>

int linearSearch(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    int x = 89;
    int ind = linearSearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}