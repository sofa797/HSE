#include <stdio.h>

int binarySearch(int* arr, int n, int x) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            return m;
        }
        if (arr[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
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
    int ind = binarySearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}