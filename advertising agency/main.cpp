#include <bits/stdc++.h>
#define mod 1000000007
#define ll unsigned long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,k; cin>>n>>k;
        ll ans = 1;
        vector<int> a(n), c(n+1), am(n+1);
        vector<vector<ll>> cb(n+1, vector<ll>(n+1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, n); ++j) {
                if(j == 0 || j == i) cb[i][j] = 1;
                else cb[i][j] = (cb[i-1][j-1] + cb[i-1][j]) % mod;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            c[a[i]]++;
        } sort(a.begin(), a.end(), greater<>());
        for (int i = 0; i < k; ++i) am[a[i]]++;
        for (int i = 0; i <= n; ++i) {
            if(am[i] != 0) {
                ans = (ans * cb[c[i]][am[i]]) % mod;
            }
        }
        cout << ans << "\n";
    }
}
