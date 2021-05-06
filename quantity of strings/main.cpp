#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> v;
#define ll unsigned long long
#define MOD 1000000007
void dfs(int n) { v[n] = true; for(int adj : g[n]) if(!v[adj]) dfs(adj); }
int main() {
    int n, m, k; cin >> n >> m >> k;
    g.resize(n + 1); v.resize(n + 1);
    for (int i = 1; i <= n - k + 1; ++i) {
        for (int j = 0; j < k/2; ++j) {
            g[i+j].push_back(i+k-j-1);
            g[i+k-j-1].push_back(i+j);
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        if(!v[i]) { dfs(i); ans *= m; ans %= MOD; }
    }
    cout << ans << "\n";
}
