#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; t.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) if(t[i].size() == 2) ans = false;
    cout << (ans ? "YES\n" : "NO\n") << "\n";
}
