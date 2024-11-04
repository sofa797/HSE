#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void*(*operation)(int , int, int**, int, int(*)(int, int));

int less(int a, int b)
{
 return a < b;
}

int greater(int a, int b)
{
 return a > b;
}

void Rows(int N, int M, int **a, int n, int(*pred)(int, int))
{
    for (int j = N - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int z = i;
            if (pred(a[i][n - 1], a[i + 1][n - 1]))
            {
                for (int u = 0; u < M; u++)
                {
                    int q = a[z][u];
                    a[z][u] = a[z + 1][u];
                    a[z + 1][u] = q;
                }
                z++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

void Columns(int N, int M, int **a, int n, int(*pred)(int, int))
{
    for (int j = M - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int z = i;
            if (pred(a[n - 1][i], a[n - 1][i + 1]))
            {
                for (int u = 0; u < N; u++)
                {
                    int q = a[u][z];
                    a[u][z] = a[u][z + 1];
                    a[u][z + 1] = q;
                }
                z++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    operation *menu = NULL;
    menu = (operation*)malloc(2 * sizeof(operation));
    menu[0] = (void*)Rows;
    menu[1] = (void*)Columns;
    int N, M; // N - rows, M - columns
    printf("Enter matrix size: ");
    scanf("%d %d", &N, &M);
    int **matrix = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)calloc(M, sizeof(int));
    }
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) 
        {
            matrix[i][j] = rand() % 100;
        }
    }
    printf("Initial matrix:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int k, l;
    printf("If you want to sort by rows, enter 1, otherwise 2: ");
    scanf("%d", &k);
    printf("If you want to sort in ascending order, enter 1, otherwise 2: ");
    scanf("%d", &l);
    if (k == 1)
    {
        int nn;
        printf("Enter the row or column number depending on the sort type: ");
        scanf("%d", &nn);
        if (l == 1)
        {
            Rows(N, M, matrix, nn, greater);
        }
        if (l == 2)
        {
            Rows(N, M, matrix, nn, less);
        }
    }
    if (k == 2)
    {
        int nn;
        printf("Enter number of row: ");
        scanf("%d", &nn);
        if (l == 1)
        {
            Columns(N, M, matrix, nn, greater);
        }
        if (l == 2)
        {
            Columns(N, M, matrix, nn, less);
        }
    }

    return 0;
}
