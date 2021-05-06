#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int,ll>>> g;
vector<ll> mx;
int d, n, m;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>d;
    g.resize(n); mx.resize(n, LONG_LONG_MAX);
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin>>a>>b>>c; a--,b--;
        g[a].push_back({b, c});
    }
    vector<int> ans;
    queue<pair<pair<int,int>,pair<vector<int>,ll>>> q; q.push({{0,0},{vector<int> (), 0}});
    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        r.second.first.push_back(r.first.first);
        if(r.first.first == n-1 && r.second.second < mx[n-1]) {
            ans = r.second.first;
            mx[n-1] = r.second.second;
        }
        if(r.first.second == d) continue;
        mx[r.first.first] = r.second.second;
        for(auto adj : g[r.first.first]) {
            ll v = max(r.second.second, adj.second);
            if(v < mx[adj.first]) q.push({{adj.first, r.first.second+1},{r.second.first, v}});
        }
    }
    if(ans.empty()) cout<<-1;
    else {
        cout << ans.size()-1 << "\n";
        for(int x : ans) cout << x+1 << " ";
    }
}
