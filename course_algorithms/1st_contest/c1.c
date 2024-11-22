#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int b[n];
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        b[j] = arr[i];
        j++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    
    return 0;
}