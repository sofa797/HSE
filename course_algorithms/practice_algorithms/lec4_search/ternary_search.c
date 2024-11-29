#include <stdio.h>

int ternarySearch(int* arr, int l, int r, int key) {
    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }
        if (key < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (key > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int ternSearch(int* arr, int n, int x) {
    return ternarySearch(arr, 0, n, x);
}

int main() {
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    int x = 89;
    int ind = ternSearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}