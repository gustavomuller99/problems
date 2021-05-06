#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> v;
void dfs(int i) {
    v[i] = true;
    for(int adj : g[i]) dfs(adj);
}
int main() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    vector<bool> add(n);
    g.resize(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) cin>>b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(a[i] % a[j] == 0) g[i].push_back(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        v = vector<bool> (n);
        int s1 = 0, s2 = 0;
        dfs(i);
        cout << i << "\n";
        for (int j = 0; j < n; j++) {
            if(v[j]) s1 += b[j];
            if(add[j] && v[j]) {
                cout << j << " ";
                s2 += b[j];
            }
        }
        cout << "\n" << s1 << " " << s2 << "\n";
        if(s1 > s2 && s1 > 0) for (int j = 0; j < n; ++j) add[j] = add[j] | v[j];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) if(add[i]) ans += b[i];
    cout << ans;
}
