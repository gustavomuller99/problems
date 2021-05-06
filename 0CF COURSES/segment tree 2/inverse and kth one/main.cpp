#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> t;
void p(int n, int lx, int rx) {
    if(t[n].first == 1) {
        /* ?????????????????/ */
    }
}
void md(int l, int r, int lx, int rx, int n = 0) {
    if(n < t.size()/2) p(n, lx, rx);
    if(lx >= l && rx <= r) {
        cout << lx << " " << rx << "\n";
        cout << t[n].second << "\n";
        t[n].second = (rx - lx + 1) - t[n].second;
        cout << t[n].second << "\n\n";
        t[n].first = 1;
        return;
    }
    if(rx < l || lx > r) return;
    int mid = (lx + rx) / 2;
    md(l, r, lx, mid, 2*n + 1);
    md(l, r, mid+1, rx, 2*n + 2);
    t[n].second = t[2*n + 1].second + t[2*n + 2].second;
    t[n].first = 0;
}
int c(int lx, int rx, int k, int n = 0) {
    if(n < t.size()/2) p(n, lx, rx);
    else return n;

    int mid = (lx + rx / 2), rt;
    if(t[2*n + 1].second > k) rt = c(lx, mid, k, 2*n + 1);
    else rt = c(mid+1, rx, k - t[2*n + 1].second, 2*n + 2);
    return rt;
}
int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k = 1; cin >> n >> m;
    while(k < n) {
        k*=2;
    } k*=2; k--;
    t.resize(k);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            md(l, r - 1, 0, k/2);
        } else {
            int kth; cin >> kth;
            cout << c(0, k/2, kth) - k/2 << "\n";
        }
    }
}