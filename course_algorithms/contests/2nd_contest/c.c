#include <stdio.h>
#include <stdlib.h>

void prinarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert(int a[], int n, int x, int val) {
    for (int i = n; i > x; i--) {
        a[i] = a[i - 1];
    }
    a[x] = val;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n], ans[n];
    int l = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            insert(ans, l, 0, n - i);
            l++;
        }
        else if (a[i] == -1) {
            ans[l] = n - i;
            l++;
        }
        else if (a[i] == 0) {
            insert(ans, l, l / 2, n - i);
            l++;
        }
    }
    prinarr(ans, n);

    return 0;
}
