#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<bool> v;
int dfs(int n, int d = 1) {
    int p = d;
    for (int i : t[n]) {
        d = max(d, dfs(i, p + 1));
    }
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    t.resize(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        if (p != -1) t[p - 1].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!v[i]) {
            v[i] = true;
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << "\n";
}
