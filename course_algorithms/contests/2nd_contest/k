#include <stdio.h>

int spasibo_za_contest[21][21][21];

void lrecurs() {
    for (int fst = 0; fst < 21; fst++) {
        for (int scnd = 0; scnd < 21; scnd++) {
            for (int thrd = 0; thrd < 21; thrd++) {
                if (fst <= 0 || scnd <= 0 || thrd <= 0) {
                    spasibo_za_contest[fst][scnd][thrd] = 1;
                }
                else if (fst > 20 || scnd > 20 || thrd > 20) {
                    spasibo_za_contest[fst][scnd][thrd] = spasibo_za_contest[20][20][20];
                }
                else {
                    spasibo_za_contest[fst][scnd][thrd] = -1;
                }
            }
        }
    }
    for (int a = 0; a < 21; a++) {
        for (int b = 0; b < 21; b++) {
            for (int c = 0; c < 21; c++) {
                if (spasibo_za_contest[a][b][c] == -1) {
                    if (a < b && b < c) {
                        spasibo_za_contest[a][b][c] = spasibo_za_contest[a][b][c - 1] + spasibo_za_contest[a][b - 1][c - 1] - spasibo_za_contest[a][b - 1][c];
                    }
                    else {
                        spasibo_za_contest[a][b][c] = spasibo_za_contest[a - 1][b][c] + spasibo_za_contest[a - 1][b - 1][c] + spasibo_za_contest[a - 1][b][c - 1] - spasibo_za_contest[a - 1][b - 1][c - 1];
                    }
                }
            }
        }
    }
}

int lrec(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        return spasibo_za_contest[20][20][20];
    }
    else {
        return spasibo_za_contest[a][b][c];
    }
}

int main() {
    int a, b, c;
    lrecurs();
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", lrec(a, b, c));

    return 0;
}
