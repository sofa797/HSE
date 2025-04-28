#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    int r, c;
    std::cin >> r >> c;
    std::vector<std::string> v(r);
    for (int i = 0; i != r; ++i) {
        std::cin >> v[i];
    }
    int si = -1, sj = -1, ei = -1, ej = -1;
    for (int i = 0; i != r; ++i) {
        for (int j = 0; j != c; ++j) {
            if (v[i][j] == 'S') {
                si = i;
                sj = j;
            }
            else if (v[i][j] == 'F') {
                ei = i;
                ej = j;
            }
        }
    }
    std::vector<std::vector<int>> ras(r, std::vector<int>(c, -1));
    std::vector<std::vector<int>> p(r, std::vector<int>(c, -1));
    std::queue<std::pair<int, int>> ocher;
    std::vector<std::vector<std::vector<int>>> matr(r, std::vector<std::vector<int>>(c));
    std::cout << "Initial labyrinth:" << std::endl;
    for (int i = 0; i != r; ++i) {
        std::cout << v[i] << std::endl;
    }
    ras[si][sj] = 0;
    ocher.push({si, sj});
    std::cout << "Graph:" << std::endl;
    std::vector<int> dx = {-1, 0, 0, 1};
    std::vector<int> dy = {0, -1, 1, 0};
    for (int i = 0; i != r; ++i) {
        for (int j = 0; j != c; ++j) {
            int z = i * c + j;
            std::vector<int> ne;
            std::cout << z << " - ";
            if (v[i][j] == '#') {
                std::cout << "None" << std::endl;
                continue;
            }
            bool f = false;
            for (int d = 0; d != 4; ++d) {
                int yi = i + dx[d];
                int yj = j + dy[d];
                if (yi >= 0 and yi < r and yj >= 0 and yj < c and v[yi][yj] != '#') {
                    int dz = yi * c + yj;
                    matr[i][j].push_back(dz);
                    std::cout << dz << " ";
                    f = true;
                }
            }
            if (!f) {
                std::cout << "None";
            }
            std::cout << std::endl;
        }
    }
    while (!ocher.empty()) {
        auto [i, j] = ocher.front();
        ocher.pop();
        if (i == ei and j == ej) {
            break;
        }
        for (int d = 0; d != 4; ++d) {
            int yi = i + dx[d];
            int yj = j + dy[d];
            if (yi >= 0 and yi < r and yj >= 0 and yj < c and v[yi][yj] != '#' and ras[yi][yj] == -1) {
                ras[yi][yj] = ras[i][j] + 1;
                p[yi][yj] = i * c + j;
                ocher.push({yi, yj});
            }
        }
    }
    std::cout << "BFS result is:" << std::endl;
    for (int i = 0; i != r; ++i) {
        for (int j = 0; j != c; ++j) {
            std::cout << ras[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}