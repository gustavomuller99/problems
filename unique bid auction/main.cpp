#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> g(n), a(n);
        for (int i = 0; i < n; ++i) {
            cin>>g[i]; g[i]--;
            a[g[i]]++;
        }
        int m = INT_MAX, ans = -1;
        for (int i = 0; i < n; ++i) {
            if(a[g[i]]==1 && g[i] < m) m = g[i], ans = i+1;
        }
        cout << ans << "\n";
    }
}
