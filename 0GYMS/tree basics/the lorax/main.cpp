#include <bits/stdc++.h>
using namespace std;
int n, q, k, timer;
vector<vector<int>> t;
vector<int> d, tin, tout;
vector<long long> s;
void dfs(int i = 0, int f = -1, int dp = 0) {
    tin[i] = ++timer;
    d[i] = dp;
    for(int adj : t[i]) {
        if(adj == f) continue;
        dfs(adj, i, dp+1);
    }
    tout[i] = timer;
}
long long c(int l, int r, int lx, int rx, int i) {
    if(lx >= l && rx <= r) return s[i];
    if(rx < l || lx > r) return 0;
    int mid = (lx + rx) / 2;
    return c(l, r, lx, mid, 2*i + 1) + c(l, r, mid+1, rx, 2*i + 2);
}
void u(int i, long long v) {
    s[i] += v;
    while(i != 0) {
        i = i/2 - (i%2 == 0);
        s[i] = s[2*i + 1] + s[2*i + 2];
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc; while(tc--) {
        timer = -1;
        cin >> n >> q; k = 1;
        while(k < n) k *= 2;
        k *= 2; k--;
        s = vector<long long> (k);
        t = vector<vector<int>> (n);
        tin = vector<int> (n);
        tout = vector<int> (n);
        d = vector<int> (n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v; u--, v--;
            t[u].push_back(v);
            t[v].push_back(u);
        }
        dfs(0);
        while(q--) {
            int a, b; long long x; cin >> a >> b >> x;
            a--, b--;
            if(x == 0) {
                if(d[b] > d[a]) swap(a, b);
                cout << abs(c(tin[a], tout[a], 0, k/2, 0)) << "\n";
            } else {
                u(tin[a] + k/2, x);
                u(tin[b] + k/2, -x);
            }
        }
    }
}
