#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minind = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minind]) {
                minind = j;
            }
        }
        int t = a[i];
        a[i] = a[minind];
        a[minind] = t;
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    bool swapped;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int q = a[j];
                a[j] = a[j + 1];
                a[j + 1] = q;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void countSort(int a[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    int* countArray = (int*)calloc(m + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        countArray[a[i]]++;
    }
    // for (int i = 1; i <= m; i++) {
    //     countArray[i] += countArray[i - 1];
    // }
    int* outputArray = (int*)malloc(n * sizeof(int));
    // for (int i = n - 1; i >= 0; i--) {
    //     outputArray[countArray[a[i]] - 1] = a[i];
    //     countArray[a[i]]--;
    //}
    int j = 0;
    for (int i = 0; i < m + 1; i++) {
        while (countArray[i] != 0) {
            outputArray[j] = i;
            countArray[i]--;
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = outputArray[i];
    }
    free(countArray);
    free(outputArray);
}

void radixSort(int a[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    for (int exp = 1; m / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(a[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            a[i] = output[i];
        }
    }
}

void insertion_sort(uint32_t* array, size_t size) {
    for (size_t i = 1; i < size; i++) {
        uint32_t key = array[i];
        size_t j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void bucket_sort(uint32_t* array, size_t size, uint32_t range_start, uint32_t range_end, size_t n_buckets) {
    uint32_t bucket_range_step = (range_end - range_start + 1) / n_buckets;
    uint32_t** buckets = malloc(n_buckets * sizeof(uint32_t*));
    size_t* buckets_size = malloc(n_buckets * sizeof(size_t));

    for (size_t i = 0; i < n_buckets; i++) {
        buckets[i] = malloc(size * sizeof(uint32_t));
        buckets_size[i] = 0;
    }

    for (size_t i = 0; i < size; i++) {
        if (array[i] < range_start) {
            buckets[0][buckets_size[0]++] = array[i];
        } else if (array[i] >= range_end) {
            buckets[n_buckets - 1][buckets_size[n_buckets - 1]++] = array[i];
        } else {
            size_t bucket_index = (array[i] - range_start) / bucket_range_step;
            buckets[bucket_index][buckets_size[bucket_index]++] = array[i];
        }
    }

    size_t output_array_offset = 0;

    for (size_t i = 0; i < n_buckets; i++) {
        insertion_sort(buckets[i], buckets_size[i]);
        for (size_t j = 0; j < buckets_size[i]; j++) {
            array[output_array_offset++] = buckets[i][j];
        }
    }

    for (size_t i = 0; i < n_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(buckets_size);
}

int main() {
    // for bucket sort

    int n;
    scanf("%d", &n);
    uint32_t a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    bucket_sort(a, n, 1, m, 2);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");



    // for other sorts

    // int n;
    // scanf("%d", &n);
    // int a[n];
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }
    // selectionSort(a, n);
    // printArray(a, n);
    // printf("\n");

    return 0;
}