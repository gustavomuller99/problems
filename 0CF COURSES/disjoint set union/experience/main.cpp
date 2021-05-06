#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> e;
int diff(int u) {
    if(u == d[u]) return e[u];
    return diff(d[u]) - e[u];
}
int g(int u) {
    while (u != d[u]) {
        u = d[u];
    }
    return u;
}
void j(int u, int v) {
    u = g(u); v = g(v);
    if(u != v) {
        if (e[v] > e[u]) swap(u, v);
        e[v] = e[u] - e[v];
        d[v] = u;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m; n++;
    d.resize(n);
    e.resize(n);
    for(int i = 0; i < n; ++i) { d[i] = i; }
    while(m--) {
        string op; cin >> op;
        if(op[0] == 'a') {
            int x, v; cin >> x >> v;
            x = g(x);
            e[x] += v;
        } else if (op[0] == 'j') {
            int x, v; cin >> x >> v;
            j(x, v);
        } else {
            int x; cin >> x;
            cout << diff(x) << "\n";
        }
    }
}
