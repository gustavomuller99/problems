#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll MOD = 1e9+7;
vector<vector<int>> t;
int n, x; ll m, k, d[100000][3][11];
void dfs(int i, int p = -1) {
    d[i][0][0] = m-k;
    d[i][1][0] = k-1;
    d[i][2][1] = 1;
    for(int adj : t[i]) {
        if(adj == p) continue;
        dfs(adj, i);
        ll tp[3][11] = {0};
        for (int j = 0; j <= x; ++j) {
            for (int l = 0; l <= j; ++l) {
                tp[0][j] = (tp[0][j] + ((d[adj][0][j-l] + d[adj][1][j-l]) * d[i][0][l])%MOD)%MOD;
                tp[1][j] = (tp[1][j] + ((d[adj][0][j-l] + d[adj][1][j-l] + d[adj][2][j-l]) * d[i][1][l])%MOD)%MOD;
                tp[2][j] = (tp[2][j] + ((d[adj][1][j-l]) * d[i][2][l])%MOD)%MOD;
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (int l = 0; l <= x; ++l) {
                d[i][j][l] = tp[j][l];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    t.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        t[v].push_back(u); t[u].push_back(v);
    }
    cin>>k>>x;
    dfs(0);
    ll ans = 0;
    for (int i = 0; i <= x; ++i)
        for (int j = 0; j < 3; ++j)
            ans += d[0][j][i], ans %= MOD;
    cout << ans;
}
