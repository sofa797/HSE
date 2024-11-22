#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        int q = arr[c1];
        arr[c1] = arr[c2];
        arr[c2] = q;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}