#include <stdio.h>

void prinarr(double a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\n");
}

double mn(double a[], int n) {
    double x = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < x) {
            x = a[i];
        }
    }
    return x;
}

double mx(double a[], int n) {
    double x = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > x) {
            x = a[i];
        }
    }
    return x;
}

void insertsort(double a[], int n) {
    for (int i = 1; i < n; i++) {
        int q = i - 1;
        double z = a[i];
        while (q >= 0 && a[q] > z) {
            a[q + 1] = a[q];
            q--;
        }
        a[q + 1] = z;
    }
}

void bucks(double a[], int n, int bins) {
    double l = mn(a, n);
    double r = mx(a, n);
    double arrbins[bins][n];
    int arrs[bins];
    for (int i = 0; i < bins; i++) {
        arrs[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < l) {
            arrbins[0][arrs[0]++] = a[i];
        }
        else if (a[i] >= r) {
            arrbins[bins - 1][arrs[bins - 1]++] = a[i];
        }
        else {
            int ind = (int)((a[i] - l) * bins / (r - l));
            if (ind >= bins) {
                ind = bins - 1;
            }
            arrbins[ind][arrs[ind]++] = a[i];
        }
    }
    for (int i = 0; i < bins; i++) {
        if (arrs[i] > 0) {
            printf("Bucket:\n");
            prinarr(arrbins[i], arrs[i]);
            insertsort(arrbins[i], arrs[i]);
            printf("Sorted bucket:\n");
            prinarr(arrbins[i], arrs[i]);
            printf("\n");
        }
    }
    int hlp = 0;
    for (int i = 0; i < bins; i++) {
        for (int j = 0; j < arrs[i]; j++) {
            a[hlp++] = arrbins[i][j];
        }
    }
    printf("Final array:\n");
    prinarr(a, n);
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("Initial array:\n");
    prinarr(a, n);
    printf("\n");
    bucks(a, n, 2 * n);

    return 0;
}
