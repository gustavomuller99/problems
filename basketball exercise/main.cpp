#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<ll>> dp(4, vector<ll>(n + 1));
    vector<ll> u(n), l(n);
    for (int i = 0; i < n; ++i) cin >> u[i];
    for (int i = 0; i < n; ++i) cin >> l[i];
    dp[0][0] = u[0]; dp[1][0] = 0; dp[2][0] = l[0]; dp[3][0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[0][i] = max(dp[2][i-1], dp[3][i-1]) + u[i];
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + l[i];
        dp[3][i] = max(dp[2][i-1], dp[3][i-1]);
    }
    cout << max(dp[0][n-1], max(dp[1][n-1], max(dp[2][n-1], dp[3][n-1])));
}
