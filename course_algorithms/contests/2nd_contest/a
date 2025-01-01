#include <stdio.h>

int main() {
    int n, m, s = 0;
    scanf("%d", &n);
    int boxes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boxes[i]);
        s += boxes[i];
    }
    int q[s];
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (boxes[i] > 0) {
            q[j] = i + 1;
            boxes[i]--;
            j++;
        }
    }
    scanf("%d", &m);
    int reqs[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &reqs[i]);
        printf("%d\n", q[reqs[i] - 1]);
    }

    return 0;
}
