#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int c[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i]) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}