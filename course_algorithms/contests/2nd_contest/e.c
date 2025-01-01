#include <stdio.h>

void prinarr(int a[], int l, int r) {
    for (int i = l; i < r; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int mer(int a[], int l, int m, int r) {
    int s1 = m - l;
    int s2 = r - m;
    int lf[s1], rt[s2];
    int i = 0, j = 0;
    for (i = 0; i < s1; i++) {
        lf[i] = a[l + i];
    }
    for (j = 0; j < s2; j++) {
        rt[j] = a[m + j];
    }
    printf("Left part: ");
    prinarr(lf, 0, s1);
    printf("Right part: ");
    prinarr(rt, 0, s2);
    int q = l;
    i = 0, j = 0;
    while (i < s1 && j < s2) {
        if (lf[i] <= rt[j]) {
            a[q++] = lf[i++];
        }
        else {
            a[q++] = rt[j++];
        }
    }
    while (j < s2) {
        a[q++] = rt[j++];
    }
    while (i < s1) {
        a[q++] = lf[i++];
    }
    printf("Merged parts: ");
    prinarr(a, l, r);
    printf("\n");
}

void msort(int a[], int l, int r) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        msort(a, l, m);
        msort(a, m, r);
        mer(a, l, m, r);
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
    prinarr(a, 0, n);
    printf("\n");
    msort(a, 0, n);

    return 0;
}
