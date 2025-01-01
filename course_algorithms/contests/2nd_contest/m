#include <stdio.h>
#include <stdbool.h>

void bin(int n) {
    int bit[32];
    int ind = 0;
    bool f = false;
    int x = -1;
    while (n > 0) {
        if ((x - n&1) != 0 || f == false) {
            bit[ind++] = n & 1;
            f = true;
            x = n & 1;
        }
        else {
            f = false;
        }
        n >>= 1;
    }
    for (int i = ind - 1; i >= 0; i--) {
        printf("%d", bit[i]);
    }
    printf("\n");
    for (int i = 0; i < ind; i++) {
        printf("%d", bit[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    bin(n);

    return 0;
}
