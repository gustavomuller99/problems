#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> s;
vector<pair<int, int>> mm;
int g(int n) {
    return d[n] = (n == d[n] ? n : g(d[n]));
}
void j(int a, int b) {
    a = g(a); b = g(b);
    if(a != b) {
        if (s[b] > s[a]) swap(a, b);
        s[a] += s[b];
        mm[a].first = min(mm[a].first, mm[b].first);
        mm[a].second = max(mm[a].second, mm[b].second);
        d[b] = a;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m; n++;
    d.resize(n);
    s.resize(n, 1);
    mm.resize(n);
    for (int i = 0; i < n; ++i) { d[i] = mm[i].first = mm[i].second = i; }
    while(m--) {
        string op; cin >> op;
        if(op[0] == 'g') {
            int u; cin >> u;
            u = g(u);
            cout << mm[u].first << " " << mm[u].second << " " << s[u] << "\n";
        } else {
            int u, v; cin >> u >> v;
            j(u, v);
        }
    }
}
