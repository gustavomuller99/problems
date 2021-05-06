#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> f, s;
int dfs(int n = 0, int dth = 1, int fth = -1) {
    s[n] = 1;
    for(int adj : t[n]) {
        if(adj == fth) continue;
        else s[n] += dfs(adj, dth+1, n);
    }
    return s[n];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    t.resize(n);
    f.resize(n);
    s.resize(n);
    f[0] = 0;
    for (int i = 1; i <= n-1; ++i) {
        int u; cin>>u; u--;
        t[i].push_back(u);
        t[u].push_back(i);
        f[i] = u;
    }
    dfs(0);
    vector<double> ans(n);
    ans[0] = 1;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int fth = q.front();
        q.pop();
        double total = 0;
        for(int adj : t[fth]) {
            if(adj == f[fth]) continue;
            total += s[adj] * 0.5;
        }
        for(int adj : t[fth]) {
            if(adj == f[fth]) continue;
            double val = ans[fth] + 1 + total - 0.5 * s[adj];
            ans[adj] = val;
            q.push(adj);
        }
    }
    for(double x : ans) cout << setprecision(20) << x << " ";
}
