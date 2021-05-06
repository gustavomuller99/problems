#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<array<int, 2>> dp(n + 1, {1000000000, 1000000000});
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            if(i < n - 1) dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i] + a[i + 1]);
            if(i < n - 1) dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}
