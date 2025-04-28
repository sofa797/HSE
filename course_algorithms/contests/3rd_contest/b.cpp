#include <iostream>
#include <vector>
using namespace std;

struct prcs {
    long long t;
    int numb;
};
struct mh {
    vector<prcs> ququ;
    bool cmp(const prcs& x, const prcs& y) {
        return (x.t > y.t or (x.t == y.t and x.numb > y.numb));
    }
    void normup(int i) {
        while (i > 0 and cmp(ququ[(i - 1) / 2], ququ[i])) {
            swap(ququ[i], ququ[(i-1) / 2]);
            i = (i-1)/2;
        }
    }
    void normdown(int i) {
        int sz = ququ.size();
        while (true) {
            int l = 2*i+1;
            int r = 2*i+2;
            int mn = i;
            if (l < sz and cmp(ququ[mn], ququ[l])) {
                mn = l;
            }
            if (r < sz and cmp(ququ[mn], ququ[r])) {
                mn = r;
            }
            if (mn == i) {
                break;
            }
            swap(ququ[i], ququ[mn]);
            i = mn;
        }
    }
    void ins(prcs pr) {
        ququ.push_back(pr);
        normup(ququ.size() - 1);
    }
    prcs del() {
        prcs mn = ququ[0];
        ququ[0] = ququ.back();
        ququ.pop_back();
        if (!ququ.empty()) {
            normdown(0);
        }
        return mn;
    }
};

int main() {
    int np;
    long long ntask;
    cin >> np;
    cin >> ntask;
    vector<long long> tsk(ntask);
    for (int i = 0; i < ntask; i++) {
        cin >> tsk[i];
    }
    mh h;
    for (int i = 0; i < np; i++) {
        h.ins({0, i});
    }
    for (int i = 0; i < ntask; i++) {
        long long tt = tsk[i];
        prcs p = h.del();
        int prnum = p.numb;
        long long stt = p.t;
        cout << prnum << " " << stt << endl;
        p.t += tt;
        h.ins(p);
    }

    return 0;
}