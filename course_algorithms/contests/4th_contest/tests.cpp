#include <iostream>

long long nod(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return nod(b, a % b);
}

long long mpow(long long x, long long y, long long n) {
    if (y == 0) {
        return 1 % n;
    }
    long long q = mpow(x, y / 2, n);
    q = (q * q) % n;
    if (y % 2 == 0) {
        return q;
    }
    else {
        return (x * q) % n;
    }
}

bool frmt(long long n, int& sophist, int& done) {
    sophist = 0, done = 0;
    for (long long i = 1; i != n; ++i) {
        if (nod(i, n) != 1) {
            sophist++;
        } else if (mpow(i, n - 1, n) == 1) {
            done++;
        } else {
            sophist++;
        }
    }
    return sophist == 0;
}

bool mrt(long long n, int& sophist, int& done1, int& done2) {
    if (n < 4) {
        return n == 2 or n == 3;
    }
    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0)  {
        d /= 2;
        s++;
    }
    sophist = done1 = done2 = 0;
    for (long long i = 1; i != n; ++i) {
        if (nod(i, n) != 1) {
            sophist++;
            continue;
        }
        long long x = mpow(i, d, n);
        if (x == 1) {
            done1++;
        } else {
            bool f = false;
            for (int r = 0; r != s; ++r) {
                if (x == n - 1) {
                    done2++;
                    f = true;
                    break;
                }
                x = x * x % n;
            }
            if (!f) {
                sophist++;
            }
        }
    }
    return sophist == 0;
}

int main() {
    long long n;
    std::cin >> n;

    int fs = 0, fd = 0;
    int mrs = 0, mrd1 = 0, mrd2 = 0;

    bool fr = frmt(n, fs, fd);
    bool mrr = mrt(n, mrs, mrd1, mrd2);

    std::cout << "Miller-Rabin test: ";
    if (mrr) {
        std::cout << "True" << " ";
    }
    else {
        std::cout << "False" << " ";
    }
    std::cout << mrs << " " << mrd1 << " " << mrd2 << std::endl;
    std::cout << "Fermat test: ";
    if (fr) {
        std::cout << "True" << " ";
    }
    else {
        std::cout << "False" << " ";
    }
    std::cout << fs << " " << fd << std::endl;

    return 0;
}