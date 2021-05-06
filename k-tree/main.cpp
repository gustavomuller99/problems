#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;
int main() {
    int n,k,d; cin>>n>>k>>d;
    vector<vector<int>> dp(n+1, vector<int> (2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            if(j < d) {
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
                dp[i][0] %= MOD;
                dp[i][1] %= MOD;
            } else {
                dp[i][1] += dp[i-j][0];
                dp[i][1] %= MOD;
                dp[i][1] += dp[i-j][1];
                dp[i][1] %= MOD;
            }
        }
    }
    cout << dp[n][1];
}