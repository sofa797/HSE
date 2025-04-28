#include <iostream>
#include <vector>
#include <algorithm>

void tsk(int v, int& k, std::vector<std::vector<int>>& vert, std::vector<bool>& pos, std::vector<int>& r, std::vector<int>& d) {
    bool f = false;
    for (int i = 0; i != v; ++i) {
        if (!pos[i] and d[i] == 0) {
            pos[i] = true;
            r.push_back(i);
            for (int j : vert[i]) {
                --d[j];
            }
            tsk(v, k, vert, pos, r, d);
            pos[i] = false;
            r.pop_back();
            for (int j : vert[i]) {
                ++d[j];
            }
            f = true;
        }
    }
    if (!f and r.size() == vert.size()) {
        ++k;
    }
}

void ts(int v, int& k, std::vector<std::vector<int>>& vert, std::vector<bool>& pos, std::vector<int>& r, std::vector<int>& d) {
    bool f = false;
    for (int i = 0; i != v; ++i) {
        if (!pos[i] and d[i] == 0) {
            pos[i] = true;
            r.push_back(i);
            for (int j : vert[i]) {
                --d[j];
            }
            ts(v, k, vert, pos, r, d);
            pos[i] = false;
            r.pop_back();
            for (int j : vert[i]) {
                ++d[j];
            }
            f = true;
        }
    }
    if (!f and r.size() == vert.size()) {
        for (int q : r) {
            std::cout << q << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int v;
    std::cin >> v;
    std::vector<std::vector<int>> vert(v, std::vector<int>(v));
    int k = 0;
    for (int i = 0; i != v; ++i) {
        int k;
        std::cin >> k;
        vert[i].resize(k);
        for (int j = 0; j != k; ++j) {
            std::cin >> vert[i][j];
        }
    }
    std::vector<bool> pos(v, false);
    std::vector<int> r;
    std::vector<int> d(v, 0);
    for (int i = 0; i != v; ++i) {
        for (int j : vert[i]) {
            ++d[j];
        }
    }
    tsk(v, k, vert, pos, r, d);
    if (k > 0) {
        std::cout << k << std::endl;
        ts(v, k, vert, pos, r, d);
    }
    else {
        std::cout << "Impossible" << std::endl;
    }

    return 0;
}