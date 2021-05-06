#include <bits/stdc++.h>
using namespace std;
vector<double> ans;
vector<vector<int>> t;
void dfs(int u = 0, int f = -1, int d = 0, double c = 1) {
    bool l = true;
    double nc = (1 / ((double) t[u].size() - (f == -1 ? 0 : 1)));
    for(int adj : t[u]) {
        if(adj == f) continue;
        l = false;
        dfs(adj, u, d+1, c * nc);
    }
    if(l) ans.push_back(d * c);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    t.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs();
    double s = 0;
    for (int i = 0; i < ans.size(); ++i) s += ans[i];
    cout << setprecision(20) << s;
}
