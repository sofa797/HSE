#include <stdio.h>
#include <stdlib.h>

void prinarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int linsearch(int a[], int n, int x) {
    int j = 0;
    int q[n];
    for (int i = 0; i < n; i++) {
        q[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            q[i] = i;
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] == -1) {
            k++;
        }
    }
    if (k == n) {
        printf("No targets");
    }
    else {
        printf("Target is found at: ");
        for (int i = 0; i < n; i++) {
            if (q[i] != -1) {
                printf("%d ", q[i]);
            }
        }
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Initial array:\n");
    prinarr(a, n);
    printf("Target element: %d\n", x);
    linsearch(a, n, x);

    return 0;
}
