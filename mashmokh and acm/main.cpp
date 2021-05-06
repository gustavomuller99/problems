#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll mod = 1e9+7;
int main() {
    int n, k; cin>>n>>k;
    vector<vector<ll>> d(k, vector<ll> (n+1));
    for (int i = 1; i <= n; ++i) d[0][i] = 1;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = j; l <= n; l += j) {
                d[i][l] = (d[i][l] + d[i-1][j]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + d[k-1][i]) % mod;
    cout << ans;
}
