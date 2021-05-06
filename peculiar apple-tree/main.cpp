#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> d;
void dfs(int n = 0, int f = -1, int dp = 0) {
    d[dp]++;
    for(int adj : t[n]) {
        if(adj == f) continue;
        dfs(adj, n, dp+1);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    t.resize(n);
    d.resize(n);
    for (int i = 1; i <= n - 1; ++i) {
        int u; cin >> u; u--;
        t[u].push_back(i);
        t[i].push_back(u);
    }
    dfs();
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += d[i] % 2;
    cout << ans;
}
