#include <iostream>
#include <vector>
using namespace std;

struct bstn {
    int val;
    int l;
    int r;
};

vector<bstn> tr;

void in(int i) {
    if (i == -1) {
        return;
    }
    in(tr[i].l);
    cout << tr[i].val << " ";
    in(tr[i].r);
}

void pr(int i) {
    if (i == -1) {
        return;
    }
    cout << tr[i].val << " ";
    pr(tr[i].l);
    pr(tr[i].r);
}

void pst(int i) {
    if (i == -1) {
        return;
    }
    pst(tr[i].l);
    pst(tr[i].r);
    cout << tr[i].val << " ";
}

int main() {
    int q;
    cin >> q;
    tr.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> tr[i].val >> tr[i].l >> tr[i].r;
    }
    in(0);
    cout << endl;
    pr(0);
    cout << endl;
    pst(0);
    cout << endl;

    return 0;
}