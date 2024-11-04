#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, M;
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
    
    int row, col, nv;
    printf("Enter indexes (row, col) or -1 to exit: ");
    scanf("%d %d", &row, &col);

    if (row == -1 || col == -1) 
    {
        return 0;
    }
    if (row >= 0 && row < N && col >= 0 && col < M) 
    {
        printf("Enter new value: ");
        scanf("%d", &nv);
        *(*(matrix + row) + col) = nv;
    }
    printf("Matrix with new value:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    
    }
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}




























// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main() {
//     int N, M;
//     printf("Enter matrix size: ");
//     scanf("%d %d", &N, &M);
//     int **matrix = (int **)calloc(N, sizeof(int *));
//     for (int i = 0; i < N; i++) {
//         matrix[i] = (int *)calloc(M, sizeof(int));
//     }
//     srand(time(0));
//     for (int i = 0; i < N; i++) 
//     {
//         for (int j = 0; j < M; j++) 
//         {
//             matrix[i][j] = rand() % 100;
//         }
//     }
//     printf("Initial matrix:\n");
//     for (int i = 0; i < N; i++) 
//     {
//         for (int j = 0; j < M; j++) 
//         {
//             printf("%4d ", matrix[i][j]);
//         }
//         printf("\n");
//     }

//     while (1) {
//         int row, col, nv;
//         printf("Enter indexes (row, col) or -1 to exit: ");
//         scanf("%d %d", &row, &col);

//         if (row == -1 || col == -1) 
//         {
//             break; 
//         }
//         if (row >= 0 && row < N && col >= 0 && col < M) 
//         {
//             printf("Enter new value: ");
//             scanf("%d", &nv);
//             *(*(matrix + row) + col) = nv;
//         }
//         printf("Matrix with new value:\n");
//         for (int i = 0; i < N; i++) 
//         {
//             for (int j = 0; j < M; j++) 
//             {
//                 printf("%4d ", matrix[i][j]);
//             }
//             printf("\n");
//         }
//     }
//     for (int i = 0; i < N; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);

//     return 0;
// }