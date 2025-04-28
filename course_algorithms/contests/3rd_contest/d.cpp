#include <iostream>
#include <vector>
using namespace std;

int srch(int q, vector<int>& p) {
    if (p[q] != q) {
        p[q] = srch(p[q], p);
    }
    return p[q];
}

void ui(int x, int y, vector<int>& p, vector<int>& hgt, vector<int>& sz, int& res) {
    int px = srch(x, p);
    int py = srch(y, p);
    if (px != py) {
        if (hgt[px] < hgt[py]) {
            p[px] = py;
            sz[py]+=sz[px];
            sz[px] = 0;
        }
        else if (hgt[px] > hgt[py]) {
            p[py] = px;
            sz[px]+=sz[py];
            sz[py] = 0;
        }
        else if (hgt[px] == hgt[py]) {
            p[py] = px;
            sz[px]+=sz[py];
            sz[py]=0;
            hgt[px]++;
        }
        int tmpmx = 0;
        if (sz[px] > sz[py]) {
            tmpmx = sz[px];
        }
        else {
            tmpmx = sz[py];
        }
        res = max(res, tmpmx);
    }
}

int main() {
    int n,m;
    cin >>n>>m;
    vector<int> v(n);
    vector<int> p(n+1);
    vector<int> hgt(n+1);
    for (int i = 0; i < n+1; i++) {
        hgt[i] = 0;
    }
    vector<int> sz(n+1);
    int res = 0;
    for (int i = 0; i< n; i++) {
        cin >> v[i];
        p[i+1] = i+1;
        sz[i+1]=v[i];
        res = max(res, sz[i+1]);
    }
    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        ui(d, s, p, hgt, sz, res);
        cout << res << endl;
    }

    return 0;
}