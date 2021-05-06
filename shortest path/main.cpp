#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,k; cin>>n>>m>>k;
    int e[n][n]; memset(e, 0, sizeof(e));
    g.resize(n);
    vector<int> ans;
    map<pair<pair<int,int>, int>, bool> mp;
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v; u--,v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 0; i < k; ++i) {
        int a,b,c; cin>>a>>b>>c; a--,b--,c--;
        mp[{{a,b}, c}] = true;
    }
    queue<pair<int, vector<int>>> q; q.push({0, vector<int>()});
    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        r.second.push_back(r.first);
        //cout << "EDGE: " << r.first + 1 << "\n";
        //cout << "PATH: "; for(int x : r.second) cout << x + 1 << " "; cout << "\n";
        if(r.first == n-1) { ans = r.second; break; }
        for(int adj : g[r.first]) {
            //cout << r.first+1 << " -> " << adj+1 << " = " << e[r.first][adj] + e[adj][r.first] << "\n";
            if(e[r.first][adj] + e[adj][r.first] < 2 && (r.second.size() < 2 || !mp[{{r.second[r.second.size()-2], r.second[r.second.size()-1]},adj}])) {
                e[r.first][adj]++;
                q.push({adj, r.second});
            }
        }
    }
    if(ans.empty()) cout << -1;
    else {
        cout << ans.size() - 1 << "\n";
        for(int x : ans) cout << x + 1 << " "; cout << "\n";
    }
}
