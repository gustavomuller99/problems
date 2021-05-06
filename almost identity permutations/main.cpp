#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n, k; cin>>n>>k;
    vector<vector<ll>> c(n+1, vector<ll> (n+1)), d(n+1, vector<ll> (n+1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, n); ++j) {
            if(j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i-1][j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i,n); ++j) {
            if(i == 0 && j == 0) d[i][j] = 1;
            else if(i == 1 && j == 0) d[i][j] = 0;
            else if(j == 0) d[i][j] = (i-1) * (d[i-1][0] + d[i-2][0]);
            else d[i][j] = c[i][j] * d[i-j][0];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; ++i) ans += d[n][n-i];
    cout << ans;
}
