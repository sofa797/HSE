// Quick Sort

#include <stdio.h>

// Partition function
int partition_lomuto(int arr[], int low, int high) {
    
    // Choose the pivot
    int pivot = arr[high];
    
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

void swap_arr(int a[], int f, int s) {
    int t = a[f];
    a[f] = a[s];
    a[s] = t;
}

int partition_hoar(int a[], int l, int r) {
    int pi = (a[l] + a[r]) / 2;
    int i = l, j = r;
    while (1) {
        while (a[i] < pi) {
            i++;
        };
        while (a[j] > pi) {
            j--;
        };
        if (i >= j) {
            return j;
        }
        swap_arr(a, i++, j--);
    }
}

// The QuickSort function implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition_lomuto(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);  // just "pi" in hoar
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
