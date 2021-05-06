#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<long long, long long>, vector<int>>> g;
vector<bool> vis;
bool dfs(int u, int v) {
    vis[u] = true;
    if(u == v) return true;
    bool r = false;
    for(int k : g[u].second) {
        if(vis[k]) continue;
        r |= dfs(k, v);
    }
    return r;
}
void add(int x, int y) {
    g.push_back({{x, y}, vector<int>()});
    for (int i = 0; i < g.size() - 1; ++i) {
        if ((g[i].first.first < x && g[i].first.second > x) || (g[i].first.first < y && g[i].first.second > y)) {
            g[g.size() - 1].second.push_back(i);
        }
        if ((x < g[i].first.first && y > g[i].first.first) || (x < g[i].first.second && y > g[i].first.second)) {
            g[i].second.push_back(g.size() - 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    while(n--) {
        int a, b, c; cin>>a>>b>>c;
        if(a == 1) {
            add(b, c);
        } else {
            vis = vector<bool> (g.size(), false);
            cout << (dfs(b-1, c-1) ? "YES\n" : "NO\n");
        }
    }
}