#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[500];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        if (q == 0) {
            int ind, val;
            scanf("%d %d", &ind, &val);
            for (int j = n; j > ind - 1; j--) {
                arr[j] = arr[j - 1];
            }
            n++;
            arr[ind - 1] = val;
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
        else if (q == 1) {
            int ind;
            scanf("%d", &ind);
            for (int j = ind - 1; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
    }

    return 0;
}