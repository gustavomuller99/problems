#include <bits/stdc++.h>
using namespace std;
struct c {string op; int u, v;};
vector<int> d;
int g(int u) { return d[u] = (d[u] == u ? u : g(d[u])); }
void j(int u, int v) {
    u = g(u); v = g(v);
    d[u] = v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    d.resize(n + 1);
    vector<c> q;
    vector<string> ans;
    for (int i = 0; i <= n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
    }
    for (int i = 0; i < k; ++i) {
        c nw; cin >> nw.op >> nw.u >> nw.v;
        q.push_back(nw);
    }
    for (auto i = q.rbegin(); i < q.rend(); ++i) {
        auto qr = *i;
        if(qr.op[0] == 'a') (g(qr.u) == g(qr.v) ? ans.emplace_back("YES") : ans.emplace_back("NO"));
        else j(qr.u, qr.v);

    }
    for(auto i = ans.rbegin(); i < ans.rend(); ++i) cout << *i << "\n";
}
