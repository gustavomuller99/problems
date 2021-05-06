#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> v;
vector<pair<int, int>> ans;
vector<vector<pair<int, pair<int, int>>>> g(7);
void dfs(int i, int e = -1, int d = -1) {
    if(e != -1) v[e] = true;
    for(auto adj : g[i]) {
        int in = adj.second.first, j = adj.first, dir = adj.second.second;
        if(v[in]) continue;
        dfs(j, in, dir);
    }
    if(e != -1) ans.emplace_back(e, d);
}
int main() {
    cin>>n;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int a,b; cin>>a>>b;
        g[a].push_back({b, {i, 1}});
        g[b].push_back({a, {i, 2}});
    }
    int cnt = 0, s = 0;
    for (int i = 0; i < 7; ++i) if(g[i].size() % 2) cnt++;
    if(cnt == 0) {
        for (int i = 0; i < 7; ++i) if(g[i].size()) s = i;
    }
    else if(cnt == 2) {
        for (int i = 0; i < 7; ++i) if(g[i].size() % 2) s = i;
    }
    v = vector<bool>(n);
    dfs(s);
    if(cnt > 2 || ans.size() != n) cout << "No solution";
    else {
        for(auto i = ans.rbegin(); i < ans.rend(); ++i) {
            cout << i->first + 1 << " " << (i->second == 1 ? '+' : '-') << "\n";
        }
    }
}
