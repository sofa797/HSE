#include <stdio.h>

void prinarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ququpart(int* a, int l, int r, int n) {
    int privind = l + (r - l) / 2;
    int priv = a[privind];
    printf("Pivot index: %d , pivot element: %d\n", privind, priv);
    int lf[r - l + 1];
    int rt[r - l + 1];
    int lfcnt = 0, rtcnt = 0;
    for (int i = l; i <= r; i++) {
        if (i == privind) continue;
        if (a[i] <= priv) {
            lf[lfcnt++] = a[i];
        } else {
            rt[rtcnt++] = a[i];
        }
    }
    for (int i = 0; i < lfcnt; i++) {
        a[l + i] = lf[i];
    }
    a[l + lfcnt] = priv;
    for (int i = 0; i < rtcnt; i++) {
        a[l + lfcnt  + i + 1] = rt[i];
    }
    printf("Array after partition: ");
    prinarr(a, n);
    printf("\n");
    return l + lfcnt;
}

void ququsort(int* a, int l, int r, int n) {
    if (l < r) {
        int priv = ququpart(a, l, r, n);
        ququsort(a, l, priv - 1, n);
        ququsort(a, priv + 1, r, n);
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
    printf("\n");
    ququsort(a, 0, n - 1, n);

    return 0;
}
