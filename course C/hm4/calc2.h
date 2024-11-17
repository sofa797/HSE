#ifndef CALC2_H
#define CALC2_H

#include <stdio.h>
#include <stdlib.h>

typedef char*(*operation)(char*, char*, int , int);

int cnt(char *b, int M)
{
    int c = 0;
    for (int i = 0; i < M; i++)
    {
        if (b[i] == '0')
        {
            c++;
        }
    }
    if (c == M)
    {
        return 1;
    }
    return 0;
}

int maxx(int n, int m)
{
    if (n > m)
    {
        return n;
    }
    else
    {
        return m;
    }
}

char* doSum(char *a, char *b, int N, int M)
{
    int q = maxx(N, M) + 2;
    char *c = (char *)calloc(q, sizeof(char));
    for (int i = 0; i < q; i++)
    {
        c[i] = '0';
    }
    c[q-1] = 0;
    int per = 0;
    int j = M - 1;
    for (int i = N - 1; i >= 0 || per == 1; i--)
    {
        int d = b[j];
        int e = a[i];
        if (i < 0) {
            e = 0;
        }
        if (j < 0)
        {
            d = 0;
        }
        int x = e + d + per;
        if (x == 2)
        {
            per = 1;
            c[q - 2] = '0';
        }
        if (x == 3)
        {
            per = 1;
            c[q - 2] = '1';
        }
        if (x == 1)
        {
            c[q - 2] = '1';
            per = 0;
        }
        if (x == 0)
        {
            c[q - 2] = '0';
            per = 0;
        }
        j--;
        q--;
    }
    return c;
}

char* doSub(char *a, char *b, int N, int M)
{
    int q = maxx(N, M);
    int l = q;
    char *c = (char *)calloc(q, sizeof(char));
    for (int i = 0; i < q; i++)
    {
        c[i] = '0';
    }
    if (N < M)
    {
        return "Error";
    }
    else
    {
        int per = 0;
        int j = M - 1;
        for (int i = N - 1; i >= 0; i--)
        {
            int d = b[j];
            int e = a[i];
            if (i < 0)
            {
                e = 0;
            }
            if (j < 0)
            {
                d = 0;
            }
            int x = e - d - per;
            if (x == 0)
            {
                c[q] = '0';
                per = 0;
            }
            if (x == 1)
            {
                c[q] = '1';
                per = 0;
            }
            if (x == -1)
            {
                per = 1;
                c[q] = '1';
            }
            if (x == -2)
            {
                per = 1;
                c[q] = '0';
            }
            j--;
            q--;
        }
    }
    int p = 0;
    for (int i = 0; i < l; i++)
    {
        if (c[i] == '1')
        {
            p = i;
            break;
        }
    }
    return c + p;
}

char* doR(char *a, char *b, int N, int M)
{
    int q = maxx(N, M) + 1;
    char *c = (char *)calloc(q, sizeof(char));
    int k = 0, r = 11;
    char *temp = (char *)calloc(1, sizeof(char));
    temp[0] = '1';
    while (r != k)
    {
        b = doSub(b, temp, M, 1);
        k++;
        if (cnt(b, M) == 1)
        {
            r = k;
        }
    }
    r = 1;
    for (int i = 0; i < q; i++)
    {
        c[i] = a[i] + '0';
    }
    c[q - 1] = 0;
    for (int j = 0; j < r; j++)
    {
        c[j] = '0';
    }
    int w = 0;
    for (int j = r; j < q - 1; j++)
    {
        c[j] = a[w] + '0';
        w++;
    }
    return c;
}

char* doL(char *a, char *b, int N, int M)
{
    int k = 0, r = 10;
    char *temp = (char *)calloc(1, sizeof(char));
    temp[0] = '1';
    while (r != k)
    {
        b = doSub(b, temp, M, 1);
        k++;
        if (cnt(b, M) == 1)
        {
            r = k;
        }
    }
    r = 1;
    int q = N + r;
    char *c = (char *)calloc(q, sizeof(char));
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + '0';
    }
    for (int i = N; i < q; i++)
    {
        c[i] = '0';
    }
    return c + r;
}

int culc() {
    operation *menu = NULL;
    menu = (operation*)malloc(4 * sizeof(operation));
    menu[0] = doSum;
    menu[1] = doSub;
    menu[2] = doR;
    menu[3] = doL;

    int N = 0, M = 0, Z = 0;
    int c;
    char *a = (char *)calloc(100, sizeof(char));
    char *b = (char *)calloc(100, sizeof(char));
    int i = 0;
    printf("Enter the value of the first number: ");
    while ((c = getchar()) != '\n')
    {
        a[i] = c - '0';
        N++;
        i++;
    }
    int j = 0;
    printf("Enter the value of the second number: ");
    while ((c = getchar()) != '\n')
    {
        b[j] = c - '0';
        M++;
        j++;
    }
    char f;
    printf("Enter the operation you want: '+' - addition, '-' - subtraction, '>' - shift right, '<' - shift left: ");
    scanf("%c", &f);
    if (f == '+')
    {
        char* res1 = menu[0](a, b, N, M);
        printf("%s\n", res1);
    }
    if (f == '-')
    {
        char* res2 = menu[1](a, b, N, M);
        printf("%s\n", res2);
    }
    if (f == '>')
    {
        char* res3 = menu[2](a, b, N, M);
        printf("%s\n", res3);
    }
    if (f == '<')
    {
        char* res4 = menu[3](a, b, N, M);
        printf("%s\n", res4);
    }
    free(a);
    free(b);

    return 0;
}

#endif