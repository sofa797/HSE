#include <stdio.h>

int main() {
    double ans = 0.0, ans1 = 0.0, dr = 0.0;
    char sign, c;
    while ((c = getchar()) != '=')
    {
        if (c == '+' || c == '-')
        {
            if (sign == '+')
            {
                ans += ans1;
            }
            else if (sign == '-')
            {
                ans -= ans1;
            }
            else{
                ans += ans1;
            }
            ans1 = 0.0;
            sign = c;
            dr = 0;
        }
        else if (c == '.')
        {
            dr = 0.1;
        }
        else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        {
            if (dr != 0)
            {
                ans1 += (int)(c - '0') * dr;
                dr *= 0.1;
            }
            else
            {
                if (ans1 != 0.0)
                {
                    ans1 *= 10;
                }
                ans1 += (int)(c - '0');
            }
        }
    }
    if (sign == '+')
    {
        ans += ans1;
    }
    else{
        ans -= ans1;
    }
    printf("%3f", ans);
    

    return 0;
}