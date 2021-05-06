#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
int dfs(int i, int p = 0) {
    int r = 1;
    for(int adj : t[i]) {
        if(adj == p) continue;
        r += dfs(adj, i);
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    t.resize(n);
    bitset<5001> a, tmp;
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        t[v].push_back(u); t[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        //cout << "node: " << i+1 << "\n";
        tmp = 0;
        for(int adj : t[i]) {
            int sz = dfs(adj, i);
            //cout << "sz: " << sz << "\n";
            tmp = tmp | (tmp << sz);
            tmp[sz] = true;
            /*for (int j = 1; j < n-1; ++j) {
                if(tmp[j]) cout << j << " ";
            }
            cout << "\n";*/
        }
        //cout << "\n";
        a |= tmp;
    }
    cout << a.count() - a[n-1] - a[0] << "\n";
    for (int i = 1; i < n-1; ++i) {
        if(a[i]) cout << i << " " << n-i-1 << "\n";
    }
}
