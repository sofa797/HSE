#include <iostream>
#include <vector>
#include <cmath>
#include <set>

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
    int f, s;
    std::cin >> f >> s;
    std::vector<bool> done(s - f + 1, false);
    std::set<int> prost;
    std::cout << "Start and finish: " << f << " " << s << std::endl;
    bool stop = false;
    if (f <= 1 and s <= 1) {
        stop = true;
        std::cout << "Primes :" << std::endl;
        std::cout << "No primes";
        return 0;
    }
    int it = 0;
    for (int i = 2; i != s; ++i) {
        if (!chck(i)) {
            continue;
        }
        std::vector<int> nit(f);
        int k = 0;
        for (int j = ((f + i - 1) / i) * i; j <= s; j += i) {
            if (j != i and j != 1 and done[j - f] == false and (!chck(j)) and j != 1) {
                done[j - f] = true;
                nit.push_back(j);
                ++k;
            }
        }
        ++it;
        if (k > 0) {
            std::cout << "Iteration : " << it << std::endl;
            for (int u : nit) {
                if (u != 0) {
                    std::cout << u << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << "Primes :" << std::endl;
    bool pr = false;
    for (int i = f; i <= s; ++i) {
        if (i > 1 and !done[i - f]) {
            std::cout << i << " ";
            pr = true;
        }
    }
    if (!pr) {
        std::cout << "No primes";
    }

    return 0;
}