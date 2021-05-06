#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    /*
     * if the matrix needs to be a tree, it also needs to be a mst
     * since for every node we get the minimal edge (kruskal like) we guarantee testing all edges in the possible tree
     * then we test the distance (i,j) and the distance (j,mst). the difference between them needs to be equal to the distance (i,mst), otherwise there is a cycle and its not a tree.
     */
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<ll>> m;
    bool ans = true;
    int n; cin >> n; m.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int k; cin >> k; m[i].push_back(k);
            if((i == j && k) || (i != j && !k)) ans = false;
            if(i > j && m[i][j] != m[j][i]) ans = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        int mst = 0;
        for (int j = 0; j < n; ++j) if(m[i][j] < m[i][mst] && i != j) mst = j;
        for (int j = 0; j < n; ++j) if(abs(m[i][j] - m[j][mst]) != m[i][mst]) ans = false;
    }
    if(ans) cout << "YES";
    else cout << "NO";
}
/*vector<int> d;
vector<int> e;
vector<vector<int>> t;
map<pair<int, int>, ll> mp;
int g(int u) { return d[u] = (d[u] == u ? u : g(d[u])); }
bool dfs(int n, int f = -1) {
    e.push_back(n);
    for(auto c : t[n]) {
        if(c != f) dfs(c, n);
    }
    e.push_back(n);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    set<pair<ll, pair<int, int>>> q;
    int n; cin >> n;
    d.resize(n), t.resize(n), e.resize(n);
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        d[i] = i;
        for (int j = 0; j < n; ++j) {
            ll w; cin >> w;
            if(i == j) { if(w != 0) ans = false; }
            else if(i > j) { if(!q.count({w, {j, i}})) ans = false; }
            else {
                if(w == 0) ans = false;
                mp[{i, j}] = w;
                q.insert({w, {i, j}});
            }
        }
    }
    if(!ans) { cout << "NO" << "\n"; return 0; }
    for(auto x : q) {
        int a = g(x.second.first), b = g(x.second.second);
        if(a != b) {
            d[a] = b;
            t[x.second.first].push_back(x.second.second);
            t[x.second.second].push_back(x.second.first);
        }
    }
    dfs(0);
}
*/