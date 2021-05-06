#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int g(int x) { return (d[x] == x ? x : d[x] = g(d[x])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) d[i] = i;
    priority_queue<pair<int, pair<int, int>>> q;
    while(m--) {
        int b, e, w; cin >> b >> e >> w;
        q.push({-w, {b, e}});
    }
    int ans = INT_MIN;
    while(!q.empty()) {
        auto r = q.top();
        q.pop();
        int a = g(r.second.first), b = g(r.second.second);
        if(a != b) {
            ans = max(ans, -r.first);
            d[a] = b;
        }
    }
    cout << ans << "\n";
}
