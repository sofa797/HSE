#include <stdio.h>

int interpolSearch(int* arr, int n, int x) {
    int l = 0, h = n - 1;
    while (l <= h && x >= arr[l] && x <= arr[h]) {
        if (l == h) {
            if (arr[l] == x) {
                return l;
            }
            else {
                return -1;
            }
        }
        int pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (x - arr[l]));
        if (arr[pos] == x) {
            return pos;
        }
        if (arr[pos] < x) {
            l = pos + 1;
        }
        else {
            h = pos - 1;
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
    int ind = interpolSearch(arr, n, x);
    printf("Element: %d, index: %d", x, ind);

    return 0;
}