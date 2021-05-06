#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
map<pair<int, int>, int> mp;
vector<int> d;
vector<pair<ll, pair<int, int>>> na;
int g(int x) { return (d[x] == x ? x : d[x] = g(d[x])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; ll s; cin >> n >> m >> s;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) d[i] = i;
    priority_queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < m; ++i) {
        int b, e, w; cin >> b >> e >> w;
        q.push({w, {b, e}});
        mp[{b, e}] = i+1;
    }
    while(!q.empty()) {
        auto r = q.top();
        q.pop();
        int a = g(r.second.first), b = g(r.second.second);
        if(a != b) {
            d[a] = b;
        } else na.push_back({r.first, {r.second.first, r.second.second}});
    }
    set<int> ans; ll sum = 0;
    sort(na.begin(), na.end());
    for (int i = 0; i < na.size(); ++i) {
        sum += na[i].first;
        if(sum <= s) ans.insert((mp[{na[i].second.first, na[i].second.second}] == 0 ? mp[{na[i].second.second, na[i].second.first}] : mp[{na[i].second.first, na[i].second.second}]));
        else break;
    }
    cout << ans.size() << "\n";
    for(auto r : ans) cout << r << " ";
}
