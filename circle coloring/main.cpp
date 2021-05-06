#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n), c(n), ans(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];
        ans[0] = a[0];
        for (int u = 1; u < n - 1; ++u) {
            if(a[u] != ans[u - 1]) ans[u] = a[u];
            else if(b[u] != ans[u - 1]) ans[u] = b[u];
            else if(c[u] != ans[u - 1]) ans[u] = c[u];
        }
        if(a[n - 1] != ans[n - 2] && a[n - 1] != ans[0]) ans[n - 1] = a[n - 1];
        else if(b[n - 1] != ans[n - 2] && b[n - 1] != ans[0]) ans[n - 1] = b[n - 1];
        else if(c[n - 1] != ans[n - 2] && c[n - 1] != ans[0]) ans[n - 1] = c[n - 1];
        for(int k : ans) cout << k << " ";
        cout << "\n";
    }
}
