#include <bits/stdc++.h>
using namespace std;
vector<int> d, f, p;
int g(int u) { return d[u] = (d[u] == u ? u : g(d[u])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    d.resize(n); f.resize(n); p.resize(n);
    for (int i = 0; i < n; ++i) d[i] = i;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        f[k - 1] = i;
    }
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) {
        int a = g(i);
        if(i + p[i] < n) {
            int b = g(i + p[i]);
            if(a != b) d[a] = b;
        }
        a = g(i);
        if(i - p[i] >= 0) {
            int b = g(i - p[i]);
            if(a != b) d[a] = b;
        }
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        int a = g(i), b = g(f[i]);
        if(a != b) ans = false;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}
