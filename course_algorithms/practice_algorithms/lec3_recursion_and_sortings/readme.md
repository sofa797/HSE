# Lecture 3. Recursion, sorting

## Merge sort
### 1 Introduction
Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.
In simple terms, we can say that the process of merge sort is to divide the array into two halves, sort each half, and then merge the sorted halves back together. This process is repeated until the entire array is sorted.
### 2 Algorithm
Merge sort is a popular sorting algorithm known for its efficiency and stability.
It follows a divide-and-conquer approach to sort a given array of elements. 
***
#### 2.1 How does merge sort work?


##### 1. Split: Recursively divide a list or array into two halves until it can no
longer be split.
##### 2. Conquer: Each subarray is sorted individually using the merge sort algorithm.
##### 3. Merge: The sorted subarrays are merged back in sorted order. The process continues until all elements from both subarrays have been merged.
#### 2.2 Illustration of merge sort
Let’s sort the array or list [38, 27, 43, 10] using merge sort.
##### 1. Divide array
• [38, 27] and [43, 10].  
• [38, 27] is divided into [38] and [27].  
• [43, 10] is divided into [43] and [10]  
##### 2. Conquer
• [38] already sorted.
• [27] already sorted.
• [43] already sorted.
• [10] already sorted.
##### 3. Combine:
• Combine [38] and [27] to get [27, 38].  
• Combine [43] and [10] to get [10, 43].  
• Concatenate [27, 38] and [10, 43] to get final sorted list [10, 27, 38, 43].  
Therefore, the sorted list is [10, 27, 38, 43].  
### 3 Implementation of merge sort
```
// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```
### 4 Complexity Analysis of Merge Sort
#### 1. Time Complexity:
• Best Case: O(n log n), When the array is already sorted or nearly
sorted.  
• Average Case: O(n log n), When the array is randomly ordered.  
• Worst Case: O(n log n), When the array is sorted in reverse order.  
#### 2. Auxiliary Space:
• O(n), Additional space is required for the temporary array used
during merging.
### 5 Advantages of Merge Sort
• Stability: Merge sort is a stable sorting algorithm, which means it maintains
the relative order of equal elements in the input array.  
• Guaranteed worst-case performance: Merge sort has a worst-case
time complexity of O(N logN), which means it performs well even on
large datasets.  
• Simple to implement: The divide-and-conquer approach is straightforward.  
• Naturally Parallel: We independently merge subarrays that makes it
suitable for parallel processing.  
### 6 Disadvantages of Merge Sort
• Space complexity: Merge sort requires additional memory to store the
merged sub-arrays during the sorting process.  
• Not in place: Merge sort is not an in-place sorting algorithm, which
means that additional memory is required to store the sorted data. This
can be a disadvantage in applications where memory usage is an issue.  
• S is lower than QuickSort overall: QuickSort is more cache friendly
since it works in-place.  

- [Контест №1 (16.11.24-17.11.24)](https://github.com/sofa797/HSE/tree/main/course%20C)
- [Контест №2 (07.12.24-08.12.24)]()
