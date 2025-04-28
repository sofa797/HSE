#include <iostream>
#include <vector>
using namespace std;

void hp(vector<int>& el, int sz, int i, vector<int>& res) {
    int mn = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l < sz and el[l] < el[mn]) {
        mn = l;
    }
    if (r < sz and el[r] < el[mn]) {
        mn = r;
    }
    if (mn != i) {
        swap(el[i], el[mn]);
        res.push_back(i);
        res.push_back(mn);
        hp(el, sz, mn, res);
    }
}

void bobstr(vector<int>& el, vector<int>& res) {
    int sz = el.size();
    for (int i = sz/2-1; i >= 0; i--) {
        hp(el, sz, i, res);
    }
}

int main() {
    int q;
    cin >> q;
    vector<int> el(q);
    for (int i = 0; i < q; i++) {
        cin >> el[i];
    }
    vector<int> res;
    bobstr(el, res);
    int ln = res.size();
    cout << res.size() / 2 << endl;
    for (int i = 0; i < ln; i+=2) {
        cout << res[i] << " " << res[i+1] << endl;
    }

    return 0;
}