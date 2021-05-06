#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,k=0; cin>>n;
        ll ans = 0;
        vector<ll> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) {
            k += b[i];
            if(k >= a[i] && i+1 < n) b[i+1] += k-a[i]+1, c[i+1] += k-a[i]+1;
            if(a[i] - 1) {
                if(i + 2 < n) b[i + 2]++;
                if(i + a[i] < n) c[i + a[i]]++;
                a[i] = max(1ll, a[i] - k);
                ans += a[i] - 1;
            }
            k -= c[i];
        }
        cout << ans << "\n";
    }
}
