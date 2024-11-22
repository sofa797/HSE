#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        b[arr[i] - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("%d", i + 1);
        }
    }

    return 0;
}