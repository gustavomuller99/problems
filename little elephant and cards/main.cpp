#include <bits/stdc++.h>
using namespace std;
set<int> a;
map<int, pair<int, int>> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v; cin >> u >> v;
        a.insert(u); a.insert(v);
        mp[u].first++;
        if(u != v) mp[v].second++;
    }
    int ans = INT_MAX;
    for(auto k : a) {
        if(mp[k].first + mp[k].second >= (n+1)/2) {
            int nd = (n+1)/2 - mp[k].first;
            ans = min(ans, max(0, nd));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
