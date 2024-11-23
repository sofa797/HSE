#include <stdio.h>

int main() {
    unsigned int a, b;
    scanf("%u %u", &a, &b);
    unsigned int ans = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char x = (a >> (i * 8)) & 0xFF;
        unsigned char y = (b >> (i * 8)) & 0xFF;
        unsigned int t = 0;
        if (x * y > 0xFF) {
            t = 0xFF;
        }
        else {
            t = x * y;
        }
        ans = ans | (t << (i * 8));
    }
    printf("%u", ans);

    return 0;
}