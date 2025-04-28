#include <iostream>
#include <vector>
#include <algorithm>

bool srch(std::vector<bool>& pos, std::vector<int>& p, std::vector<std::vector<int>>& m, int s, int n) {
    if (p.size() == s * s) {
        return true;
    }
    for (int u : m[n]) {
        if(!pos[u]) {
            pos[u] = true;
            p.push_back(u);
            if (srch(pos, p, m, s, u)) {
                return true;
            }
            pos[u] = false;
            p.pop_back();
        }
    }
    return false;
}

int main() {
    int s;
    std::cin >> s;
    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<int>> pole(s, std::vector<int>(s));
    std::vector<bool> pos(s * s, false);
    std::vector<int> p;
    int q = 0;
    for (int i = 0; i != s; ++i) {
        for (int j = 0; j != s; ++j) {
            pole[i][j] = q;
            ++q;
        }
    }
    std::vector<std::vector<int>> m(s * s);
    std::cout << "Graph:" << std::endl;
    for (int i = 0; i != s; ++i) {
        for (int j = 0; j != s; ++j) {
            std::vector<int> v;
            std::cout << pole[i][j] << " - ";
            int i1 = i - 2;
            int j1 = j - 1;
            if (i1 >= 0 and i1 < s and j1 >= 0 and j1 < s) {
                v.push_back(pole[i1][j1]);
                m[pole[i][j]].push_back(pole[i1][j1]);
            }
            int i2 = i - 2;
            int j2 = j + 1;
            if (i2 >= 0 and i2 < s and j2 >= 0 and j2 < s) {
                v.push_back(pole[i2][j2]);
                m[pole[i][j]].push_back(pole[i2][j2]);
            }
            int i3 = i + 2;
            int j3 = j - 1;
            if (i3 >= 0 and i3 < s and j3 >= 0 and j3 < s) {
                v.push_back(pole[i3][j3]);
                m[pole[i][j]].push_back(pole[i3][j3]);
            }
            int i4 = i + 2;
            int j4 = j + 1;
            if (i4 >= 0 and i4 < s and j4 >= 0 and j4 < s) {
                v.push_back(pole[i4][j4]);
                m[pole[i][j]].push_back(pole[i4][j4]);
            }
            int i5 = i + 1;
            int j5 = j + 2;
            if (i5 >= 0 and i5 < s and j5 >= 0 and j5 < s) {
                v.push_back(pole[i5][j5]);
                m[pole[i][j]].push_back(pole[i5][j5]);
            }
            int i6 = i + 1;
            int j6 = j - 2;
            if (i6 >= 0 and i6 < s and j6 >= 0 and j6 < s) {
                v.push_back(pole[i6][j6]);
                m[pole[i][j]].push_back(pole[i6][j6]);
            }
            int i7 = i - 1;
            int j7 = j + 2;
            if (i7 >= 0 and i7 < s and j7 >= 0 and j7 < s) {
                v.push_back(pole[i7][j7]);
                m[pole[i][j]].push_back(pole[i7][j7]);
            }
            int i8 = i - 1;
            int j8 = j - 2;
            if (i8 >= 0 and i8 < s and j8 >= 0 and j8 < s) {
                v.push_back(pole[i8][j8]);
                m[pole[i][j]].push_back(pole[i8][j8]);
            }
            std::sort(v.begin(), v.end());
            std::sort(m[pole[i][j]].begin(), m[pole[i][j]].end());
            for (int u : v) {
                std::cout << u << " ";
            }
            std::cout << std::endl;
        }
    }
    p.push_back(pole[x][y]);
    pos[pole[x][y]] = true;
    std::cout << "Hamiltonian path:" << std::endl;
    if (srch(pos, p, m, s, pole[x][y])) {
        std::vector<std::vector<int>> b(s, std::vector<int>(s, -1));
        for (int i = 0; i != p.size(); ++i) {
            int idx = p[i];
            int x = idx / s;
            int y = idx % s;
            b[x][y] = i;
        }
        for (int i = 0; i != s; ++i) {
            for (int j = 0; j != s; ++j) {
                std::cout << b[i][j];
                if (j < s - 1) std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "No way" << std::endl;
    }    

    return 0;
}