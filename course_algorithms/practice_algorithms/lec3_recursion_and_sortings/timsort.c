#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

void insertionSort(int a[], int l, int r) {
    for (int i = l; i < r; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

int minRun(int n) {
    int r = 0;
    while (n <= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void timSort(int a[], int n) {
    int minrun = minRun(n);
    for (int i = 0; i < n; i += minrun) {
        insertionSort(a, i, min(i + minrun - 1, n - 1));
    }
    for (int i = minrun; i < n; i *= 2){
        for (int j = 0; j < n; j += 2 * i) {
            int mid = j + i - 1;
            int r = min(mid + 1 + i - 1, n - 1);
            if (mid < r) {
                merge(a, j, mid, r);
            }
        }
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7, 1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 31, 36, 27, 17, 4, 28, 37, 13, 9, 21, 44, 45, 15, 1, 5, 6, 32, 49, 18, 26, 10, 38, 14, 29, 33, 39, 8, 24, 25, 22, 12, 30, 34, 11, 2, 16, 40, 23, 43, 48, 41, 20, 7, 42, 46, 35, 3, 50, 47, 19};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    timSort(arr, arr_size);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
