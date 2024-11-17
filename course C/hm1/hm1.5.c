#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

int main() {
    int a[SIZE] = {0};
    srand (time(0));
    int n;
    int l;
    scanf("%d", &n);
    for (int i = 0; i < n*n; i++)
    {
        a[i] = rand() % 201 - 100;
    }

    printf("Initial matrix:\n");
    int z = 0, u = 0;
    for (int i = 0; i < 5; i++)
    {
        while (u < n)
        {
            printf("%4d ", a[z]);
            z++;
            u++;
        }
        u = 0;
        printf("\n");
    }
    printf("\n");
    printf("Matrix reflected with respect to the main diagonal:\n");

    int q = 0, j = 0;
    for (int i = 0; i < 5; i++)
    {
        while (j < n)
        {
            printf("%4d ", a[q]);
            q += 5;
            j++;
        }
        q = i+1;
        j = 0;
        printf("\n");
    }
    printf("\n");
    printf("Matrix reflected with respect to the side diagonal\n");
    int g = n*n-1, h = 0;
    for (int i = 0; i < 5; i++)
    {
        while (h < n)
        {
            printf("%4d ", a[g]);
            g--;
            h++;
        }
        h = 0;
        printf("\n");
    }


    return 0;
}