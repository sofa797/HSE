#include <stdio.h>

void prinarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insersort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int tar = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tar) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tar;
        printf("Insertion - Element #%d\n", i);
        prinarr(a, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Initial array:\n");
    prinarr(a, n);
    insersort(a, n);

    return 0;
}
