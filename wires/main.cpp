#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<pair<ll, vector<int>>> g;
vector<bool> v;
map<ll, int> r;
map<ll, vector<int>> e;
vector<int> l;
int last;
void dfs(int u, int f = -1) {
    if(v[u]) return;
    v[u] = true;
    last = g[u].first;
    for(int adj : g[u].second) {
        if(adj == f) continue;
        dfs(adj, u);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, k=1; cin>>n;
        g = vector<pair<ll, vector<int>>>(2*n+2);
        v = vector<bool>(2*n+2);
        r = map<ll, int>();
        e = map<ll, vector<int>>();
        l = vector<int>();
        for (int i = 0; i < n; ++i) {
            ll x,y; cin>>x>>y;
            if(r[x] == 0) r[x] = k, g[k].first = x, k++;
            if(r[y] == 0) r[y] = k, g[k].first = y, k++;
            e[x].push_back(i+1), e[y].push_back(i+1);
            x=r[x], y=r[y];
            g[x].second.push_back(y), g[y].second.push_back(x);
        }
        int cc = 0;
        for (int i = 1; i < k; ++i) {
            if(!v[i]) cc++, dfs(i), l.push_back(last);
        }
        cout << cc-1 << "\n";
        for (int i = 0; i < cc-1; ++i) {
            cout << e[l[i]][0] << " " << l[i] << " " << l[l.size() - 1] << "\n";
        }
    }
}
