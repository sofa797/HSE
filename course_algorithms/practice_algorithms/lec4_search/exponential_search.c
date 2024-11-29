#include <stdio.h>

int min(int n, int m) {
    if (n < m) {
        return n;
    }
    return m;
}

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int exponentSearch(int* arr, int n, int x) {
    if (arr[0] == x) {
        return 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x) {
        i = i * 2;
    }
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    int x = 89;
    int ind = exponentSearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}