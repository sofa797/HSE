#ifndef CALC10_H
#define CALC10_H

#include <stdio.h>
#include <stdlib.h>

int doSum(int a, int b)
{
    return a + b;
}

int doSub(int a, int b)
{
    return a - b;
}

int doMul(int a, int b)
{
    return a * b;
}

int doDiv(int a, int b)
{
    if (b == 0)
        exit(-1);
    return a / b;
}

int culc() {
    int(**menu)(int, int) = NULL;
    int op;
    int a, b;
    menu = (int(**)(int, int)) malloc(4 * sizeof(int(*)(int, int)));
    menu[0] = doSum;
    menu[1] = doSub;
    menu[2] = doMul;
    menu[3] = doDiv;
    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);
    printf("enter operation [0 - add, 1 - sub, 2 - mul, 3 - div]: ");
    scanf("%d", &op);
    if (op >= 0 && op < 4)
    {
    printf("%d\n", menu[op](a, b));
    }
    free(menu);

    return 0;
}

#endif