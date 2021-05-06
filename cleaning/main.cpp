#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n; bool ans = false;
        vector<ll> a(n+1), p(n+2), s(n+2);
        for (int i = 1; i <= n; ++i) cin>>a[i];
        for (int i = 1; i <= n; ++i) {
            if(p[i-1] > a[i] || p[i-1] == -1) p[i] = -1;
            else p[i] = a[i] - p[i-1];
        }
        for (int i = n; i >= 0; --i) {
            if(s[i+1] > a[i] || s[i+1] == -1) s[i] = -1;
            else s[i] = a[i] - s[i+1];
        }
        if(p[n] == 0) ans = true;
        for (int i = 0; i < n-1; ++i) {
            if(p[i] == -1 || s[i+3] == -1) continue;
            if(p[i] <= a[i+2] && s[i+3] <= a[i+1] && a[i+2] - p[i] == a[i+1] - s[i+3]) ans = true;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
