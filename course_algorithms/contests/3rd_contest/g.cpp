#include <iostream>
using namespace std;

#define SZ 100000

struct st {
    int v[SZ];
    int mvx[SZ];
    int up;
};

void stmx(st &s) {
    s.up = -1;
}

bool empt(st &s) {
    return s.up == -1;
}

bool over(st &s) {
    return s.up == SZ - 1;
}

void add(st &s, int val) {
    s.up++;
    s.v[s.up] = val;
    if (s.up == 0) {
        s.mvx[s.up] = val;
    }
    else {
        s.mvx[s.up] = max(s.mvx[s.up - 1], val);
    }
}

void pop(st &s) {
    if (empt(s)) {
        return;
    }
    s.up--;
}

int getmx(st &s) {
    return s.mvx[s.up];
}

int main() {
    st s;
    stmx(s);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string com;
        cin >> com;
        if (com == "push") {
            int val;
            cin >> val;
            add(s, val);
        }
        else if (com == "pop") {
            pop(s);
        }
        else if (com == "max") {
            int res = getmx(s);
            cout << res << endl;
        }
    }

    return 0;
}