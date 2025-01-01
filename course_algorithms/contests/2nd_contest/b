#include <stdio.h>

void prinarr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int binsearch(int a[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        printf("%d(%d) ", a[m], m);
        if (a[m] == x) {
            printf("\n");
            return m;
        }
        if (a[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    printf("\n");
    return -1;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Initial array:\n");
    prinarr(a, n);
    printf("Target element: %d\n", target);
    printf("Search history: ");
    int ans = binsearch(a, 0, n - 1, target);
    if (ans > -1) {
        printf("Target is found at: %d\n", ans);
    }
    else {
        printf("No targets");
    }

    return 0;
}
