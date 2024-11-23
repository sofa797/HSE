#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    long r[n], c[m];
    for (int i = 0; i < n; i++) {
        r[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r[i] += arr[i][j];
            c[j] += arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%ld ", r[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%ld ", c[i]);
    }

    return 0;
}