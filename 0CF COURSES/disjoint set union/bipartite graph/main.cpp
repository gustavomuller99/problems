#include <bits/stdc++.h>
using namespace std;
vector<int> d, c;
pair<int, int> g(int u) {
    if(u == d[u]) return {u, 0};
    else {
        auto rt = g(d[u]);
        d[u] = rt.first;
        c[u] += rt.second;
        return {d[u], c[u]};
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    d.resize(n); int shift = 0;
    c.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        int op, a, b; cin >> op >> a >> b;
        if(op) {
            int x = (a + shift)%n, y = (b + shift)%n;
            int d1 = g(x).second, d2 = g(y).second;
            if(d1%2 == d2%2) cout << "YES\n", shift++;
            else cout << "NO\n";
        } else {
            int x = (a + shift)%n, y = (b + shift)%n;
            auto x1 = g(x), y1 = g(y);
            d[x1.first] = y1.first;
            c[x1.first] = c[y1.first] + 1;
        }
    }
}
