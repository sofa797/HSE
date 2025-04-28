#include <iostream>
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
    bstn* l;
    bstn* r;
};

bool chck(bstn* rt, long long mn, long long mx) {
    if (!rt) {
        return 1;
    }
    if (rt->val < mn or rt->val >= mx) {
        return 0;
    }
    return chck(rt->l, mn, rt->val) and chck(rt->r, rt->val, mx);
}

bstn* bst() {
    int q;
    cin >> q;
    if (q == 0) {
        return nullptr;
    }
    bstn** nd = new bstn*[q]();
    for (int i = 0; i < q; i++) {
        nd[i] = nullptr;
    }
    for (int i = 0; i < q; i++) {
        int val;
        int l;
        int r;
        cin >> val >> l >> r;
        if (!nd[i]) {
            nd[i] = new bstn;
            nd[i]->val = val;
            nd[i]->l = nullptr;
            nd[i]->r = nullptr;
        }
        nd[i]->val = val;
        if (l != -1) {
            if (!nd[l]) {
                nd[l] = new bstn;
                nd[l]->val = val;
                nd[l]->l = nullptr;
                nd[l]->r = nullptr;
            }
            //nd[l]->val = val;
            nd[i]->l = nd[l];
        }
        if (r != -1) {
            if (!nd[r]) {
                nd[r] = new bstn;
                nd[r]->val = val;
                nd[r]->l = nullptr;
                nd[r]->r = nullptr;
            }
            //nd[r]->val = val;
            nd[i]->r = nd[r];
        }
    }
    bstn* rt = nd[0];
    return rt;
}

int main() {
    bstn* rt = bst();
    if (chck(rt, -pow(31), pow(31) - 1)) {
        cout << "CORRECT" << endl;
    }
    else {
        cout << "INCORRECT" << endl;
    }

    return 0;
}