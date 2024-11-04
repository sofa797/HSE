#include <stdio.h>

int nod(int a, int b)
{
    int div;
    if (a == b)
    {
        return a;
    }
    int d = a - b;
    if (d < 0)
    {
        d = -d;
        div = nod(a, d);
    }
    else
    {
        div = nod (b, d);
    }
    return div;
}

int main() {
    int a, b;
    printf("Enter values of numbers to find NOD: ");
    scanf("%d %d", &a, &b);
    printf("%d", nod(a, b));

    return 0;
}