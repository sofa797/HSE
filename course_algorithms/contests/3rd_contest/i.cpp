#include <iostream>
#include <vector>
using namespace std;

int pow(int a) {
    int x = 1;
    for (int i = 1; i <= a; i++) {
        x *= 2;
    }
    return x;
}

struct bstn {
    int val;
    int l;
    int r;
};

bool chck(const vector<bstn>& tr) {
    const long long sz = 100000;
    int st[sz];
    long long rst[sz][2];
    int up = -1;
    st[++up] = 0;
    rst[up][0] = -pow(31);
    rst[up][1] = pow(31) - 1;
    while (up >= 0) {
        int i = st[up];
        long long mn = rst[up][0];
        long long mx = rst[up][1];
        up--;
        if (i == -1) {
            continue;
        }
        const bstn& n = tr[i];
        if (n.val < mn or n.val >= mx) {
            return 0;
        }
        st[++up] = n.r;
        rst[up][0] = n.val;
        rst[up][1] = mx;
        st[++up] = n.l;
        rst[up][0] = mn;
        rst[up][1] = n.val;
    }
    return 1;
}

int main() {
    int q;
    cin >> q;
    if (q == 0) {
        cout << "CORRECT" << endl;
        return 0;
    }
    vector<bstn> tr(q);
    for (int i = 0; i < q; i++) {
        cin >> tr[i].val >> tr[i].l >> tr[i].r;
    }
    if (chck(tr)) {
        cout << "CORRECT" << endl;
    }
    else {
        cout << "INCORRECT" << endl;
    }

    return 0;
}