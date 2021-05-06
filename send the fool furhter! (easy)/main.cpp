#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> t;
int dfs(int n, int f, int c) {
    int sz = 0;
    for (int i = 0; i < t[n].size(); ++i) {
        if(t[n][i].first != f) {
            int r = dfs(t[n][i].first, n, t[n][i].second);
            if(sz < r) sz = r;
        }
    }
    return c + sz;
}
int main() {
    int n; cin>>n;
    t.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v,c; cin>>u>>v>>c;
        t[u].push_back(make_pair(v,c));
        t[v].push_back(make_pair(u,c));
    }
    int ans = dfs(0,0,0);
    cout<<ans<<endl;
}
