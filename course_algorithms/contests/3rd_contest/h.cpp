#include <iostream>
#include <vector>
using namespace std;

int h(const vector<vector<int>>& tr, int n) {
    if (tr[n].empty()) {
        return 1;
    }
    int mx = 0;
    for (int c : tr[n]) {
        mx = max(mx, h(tr, c));
    }
    return mx + 1;
}

int main() {
    int q;
    cin >> q;
    vector<int> p(q);
    vector<vector<int>> tr(q);
    for (int i = 0; i < q; i++) {
        cin >> p[i];
        if (p[i] != -1) {
            tr[p[i]].push_back(i);
        }
    }
    int rt = -1;
    for (int i = 0; i < q; i++) {
        if (p[i] == -1) {
            rt = i;
            break;
        }
    }
    cout << h(tr, rt) << endl;

    return 0;
}