#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> nxt;
int g(int x) { return d[x] = (d[x] == x ? x : g(d[x])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    d.resize(n + 1);
    nxt.resize(n + 1);
    for (int i = 0; i <= n; ++i) { d[i] = i; nxt[i] = i+1; }
    for(;q--;) {
        int op, x, y; cin >> op >> x >> y;
        if(x > y) swap(x, y);
        if(op == 1) d[g(x)] = g(y);
        else if (op == 2) {
            int py = g(y);
            while(x < y) {
                int nx = nxt[x], px = g(x);
                nxt[x] = nxt[y];
                d[px] = py;
                x = nx;
            }
        } else cout << (g(x) == g(y) ? "YES" : "NO") << "\n";
    }
}
