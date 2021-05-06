#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> v;
int e = 0;
void dfs(int n, int f = -1) {
    v[n] = 1;
    for (int i = 0; i < g[n].size(); ++i) {
        if(g[n][i] != f) {
            if(v[g[n][i]]) e++;
            else dfs(g[n][i], n);
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    v.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    bool ans = true;
    for (int i = 0; i < n; ++i) ans &= v[i];
    if(ans && e == 2) cout << "FHTAGN!\n";
    else cout << "NO\n";
}
