#include <stdio.h>
/* подcчет цифр, cимволов-разделителей и прочих cимволов */ 
int main()
{
    int i, c, z = 0;
    char mas[256], cnt[256];
    for (int i = 0; i < 256; i++)
    {
        mas[i] = 0;
        cnt[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        int q = c;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + ('a' - 'A');
        }
        if (cnt[c] == 0)
        {
            mas[z] = c;
            z++;
        }
        cnt[c]++;
    }
    for (int i = 0; i < z-1; i++)
    {
        printf("%c: %d\n", mas[i], cnt[mas[i]]);
    }

}