#include <iostream>
#include <cmath>

bool chck(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= pow(n, 0.5); ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        while (n % i == 0 and chck(i)) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    return 0;
}