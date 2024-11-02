#include <stdio.h>

char a[100];
char kb[100], kd[100];
int main() {
    char c;
    for (int i = 0; i < 100; i++)
    {
        kb[i] = 0;
        kd[i] = 0;
    }
    for (int i = 0; i < 100; ++i)
        a[i] = 0;
    int z = 0;
    while ((c = getchar()) != EOF && z < 100)
    {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
        {
            a[z] = c - 'A';
            kb[c - 'A']++;
        }
        else if (c >= '0' && c <= '9')
        {
            a[z] = c - '0';
            kd[c - '0']++;
        }
        z++;
    }
    for (int i = 0; i < z-1; i++)
    {
        if (kd[a[i]] >= 1)
        {
            printf("%d ", a[i]);
        }
        else if (kb[a[i]] >= 1)
        {
            printf("%c ", (char)(a[i]+65));
        }
    }
    printf("\n");
    for (int i = z-2; i >= 0; i--)
    {
        if (kd[a[i]] >= 1)
        {
            printf("%d ", a[i]);
        }
        else if (kb[a[i]] >= 1)
        {
            printf("%c ", (char)(a[i]+65));
        }
    }
    printf("\n");
    for (int i = z-2; i >= 0; i--)
    {
        int m = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j+1])
            {
                int q = a[j];
                a[j] = a[j+1];
                a[j+1] = q;
                m = 0;
            }
        }
        if (m)
        {
            break;
        }
    }
    for (int i = 0; i < z-1; i++)
    {
        if (kd[a[i]] >= 1)
        {
            printf("%d ", a[i]);
        }
        else if (kb[a[i]] >= 1)
        {
            printf("%c ", (char)(a[i]+65));
        }
    }



    return 0;
}