#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,k,p; cin>>n>>k>>p;
    int d[n][k+1][p], dp[n][k+1];
    memset(dp, 0, sizeof(dp)); memset(d, 0, sizeof(d));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i], a[i] %= p;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l < p; ++l) {
                if(l == a[i]) d[i][j][l] = (i > 0 ? dp[i-1][j-1] : 0) + a[i];
                if(i > 0) d[i][j][l] = max(d[i][j][l], d[i-1][j][(l-a[i]+p)%p] - l + (a[i] + l)%p);
            }
            for (int l = 0; l < p; ++l) {
                dp[i][j] = max(dp[i][j], d[i][j][l]);
            }
        }
    }
    cout << dp[n-1][k];
}
