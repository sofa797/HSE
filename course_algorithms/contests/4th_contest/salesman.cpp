#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> m(n, std::vector<int>(n));
    int mnk = 1000000;
    std::vector<int> kp;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cin >> m[i][j];
        }
    }
    for (int s = 0; s != n; ++s) {
        std::vector<int> p;
        std::vector<bool> pos(n, false);
        int now = s;
        int k = 0;
        bool f = true;
        pos[now] = true;
        p.push_back(now);
        for (int i = 1; i != n; ++i) {
            int sled = -100000;
            int mn = 1000000;
            for (int j = 0; j != n; ++j) {
                if (m[now][j] > 0 and m[now][j] < mn and !pos[j]) {
                    mn = m[now][j];
                    sled = j;
                }
            }
            if (sled == -100000) {
                f = false;
                break;
            }
            k += mn;
            pos[sled] = true;
            p.push_back(sled);
            now = sled;
        }
        if (f and m[now][s] > 0) {
            k += m[now][s];
            p.push_back(s);
            if (k < mnk) {
                mnk = k;
                kp = p;
            }
        }
    }
    if (mnk == 1000000) {
        std::cout << "Lost" << std::endl;
    }
    else {
        std::cout << "Path:" << std::endl;
        for (int i : kp) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Cost: " << mnk;
    }

    return 0;
}