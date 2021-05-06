#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int g(int u) {
    if(d[u] < 0) return d[u];
    return d[u] = (d[u] == u ? u : g(d[u]));
}
void j(int u, int v) {
    u = g(u); v = g(v);
    d[u] = v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    d.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    while(m--) {
        char op; cin >> op;
        if(op == '?') {
            int x; cin >> x; x--;
            cout << g(x) + 1 << "\n";
        } else {
            int x; cin >> x; x--;
            if(x < n - 1) j(x, x+1);
            else d[x] = -2;
        }
    }
}
