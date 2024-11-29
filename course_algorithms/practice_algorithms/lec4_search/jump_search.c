#include <stdio.h>
#include <math.h>

int jumpSearch(int* arr, int n, int x) {
    int i = 0;
    int m = sqrt(n);
    while(arr[m] <= x && m < n) {
        i = m;
        m += sqrt(n);
        if (m > n - 1) {
            return -1;
        }
    }
    for (int j = i; j < m; j++) {
        if (arr[j] == x) {
            return j;
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
    int ind = jumpSearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}