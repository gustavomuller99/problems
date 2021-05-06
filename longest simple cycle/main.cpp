#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll n, ans = 0, curr = 0; cin>>n;
        vector<ll> c(n), a(n), b(n);
        for (int i = 0; i < n; ++i) cin>>c[i];
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) cin>>b[i];
        curr = abs(a[1] - b[1]) + 1;
        for (int i = 1; i < n-1; ++i) {
            ans = max(ans, curr + c[i]);
            if(a[i+1] == b[i+1]) curr = 1;
            else {
                curr += (c[i] - max(a[i+1], b[i+1])) + min(a[i+1], b[i+1]) + 1;
                if(abs(a[i+1] - b[i+1]) + 1 > curr) curr = abs(a[i+1] - b[i+1]) + 1;
            }
        }
        curr += c[n-1];
        ans = max(ans, curr);
        cout << ans << "\n";
    }
}
