#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int g(int u) {
    return d[u] = (u == d[u] ? u : g(d[u]));
}
void j(int u, int v) {
    u = g(u); v = g(v);
    d[u] = v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    d.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p; p--;
        p = g(p);
        cout << p + 1 << " ";
        j(p, (p + 1) % n);
    }
}
