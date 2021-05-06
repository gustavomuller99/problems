#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
vector<vector<int>> t;
vector<int> tin, tout;
vector<double> w;
int timer = -1, n, k = 1, q;
void dfs(int i = 0, int f = 0) {
    tin[i] = ++timer;
    for(int adj : t[i]) {
        if(adj == f) continue;
        dfs(adj, i);
    }
    tout[i] = timer;
}
double c(int l, int r, int lx, int rx, int i) {
    if(lx >= l && rx <= r) return w[i];
    if(rx < l || lx > r) return 0;
    int mid = (lx + rx) / 2;
    return c(l, r, lx, mid, 2*i + 1) + c(l, r, mid+1, rx, 2*i + 2);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; t.resize(n); tin.resize(n); tout.resize(n);
    while(k <= n) k *= 2;
    k *= 2; k--; w.assign(k, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs();
    cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int x; ll y; cin >> x >> y; x--;
            int index = tin[x] + k/2;
            w[index] = (double) log2(y);
            while(index != 0) {
                index = index / 2 - (index % 2 == 0);
                w[index] = w[index*2 + 1] + w[index*2 + 2];
            }
        } else {
            int x, y; cin >> x >> y; x--, y--;
            double rx = c(tin[x], tout[x], 0, k/2, 0);
            double ry = c(tin[y], tout[y], 0, k/2, 0);
            double ans = rx - ry;
            cout << setprecision(20) << min((double) 1000000000, pow(2, ans)) << "\n";
        }
    }
}
