#include <iostream>
#include <vector>
using namespace std;

int sz;
vector<vector<string>> tbl;

int hfun(const string& s) {
    long long haval = 0;
    long long pow = 1;
    for (int i = 0; i < s.length(); i++) {
        haval = (haval + (s[i] * pow) % 1000000007) % 1000000007;
        pow = (pow * 263) % 1000000007;
    }
    return haval % sz;
}

void ins(const string& s) {
    int i = hfun(s);
    for (int j = 0; j < tbl[i].size(); j++) {
        if (tbl[i][j] == s) {
            return;
        }
    }
    tbl[i].insert(tbl[i].begin(), s);
}

void del(const string& s) {
    int i = hfun(s);
    for (int j = 0; j < tbl[i].size(); j++) {
        if (tbl[i][j] == s) {
            tbl[i].erase(tbl[i].begin() + j);
            return;
        }
    }
}

bool fnd(const string& s) {
    int i = hfun(s);
    for (int j = 0; j < tbl[i].size(); j++) {
        if (tbl[i][j] == s) {
            return 1;
        }
    }
    return 0;
}

void chk(int i ) {
    if (i < 0 or i >= sz) {
        return;
    }
    if (tbl[i].empty()) {
        cout << endl;
    }
    else {
        for (int j = 0; j < tbl[i].size(); j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << tbl[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> sz >> n;
    tbl.resize(sz);
    for (int y = 0; y < n; y++) {
        string com;
        string s;
        int i;
        cin >> com;
        if (com == "add") {
            cin >> s;
            ins(s);
        }
        else if (com == "del") {
            cin >> s;
            del(s);
        }
        else if (com == "find") {
            cin >> s;
            if (fnd(s)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (com == "check") {
            cin >> i;
            chk(i);
        }
    }
    return 0;
}