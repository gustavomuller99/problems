#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int g(int x) { return d[x] = (d[x] == x ? x : g(d[x])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n;
    priority_queue<pair<int, pair<int, int>>> qu;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) { int t; cin >> t; d[i] = i; }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        qu.push({-c, {a, b}});
    }
    unsigned long long ans = 0;
    while(!qu.empty()) {
        auto r = qu.top();
        qu.pop();
        int a = g(r.second.first), b = g(r.second.second);
        if(a != b && d[r.second.second] == r.second.second) {
            ans += -r.first;
            d[b] = a;
        }
    }
    bool ps = true;
    for (int i = 2; i <= n; ++i) ps &= g(d[i]) == g(d[i-1]);
    if(ps) cout << ans << "\n";
    else cout << -1 << "\n";
}
