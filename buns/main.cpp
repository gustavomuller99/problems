#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,c,d,ans=0; cin>>n>>m>>c>>d;
    int dp[m][n+1]; memset(dp, 0, sizeof(dp));
    vector<pair<int, pair<int,int>>> a;
    for (int i = 0; i < m; ++i) {
        int ai,bi,ci,di; cin>>ai>>bi>>ci>>di;
        a.push_back({ai/bi, {ci, di}});
    }
    for (int i = 0; i < n+1; ++i)
        if(i - c >= 0 && (dp[0][i-c] || i - c == 0)) dp[0][i] = dp[0][i-c] + d;
    for (int i = 0; i < m; ++i) {
        int ci = a[i].second.first, di = a[i].second.second;
        if(i) for (int j = 0; j < n+1; ++j) dp[i][j] = dp[i-1][j];
        for (int j = 0; j < a[i].first; ++j) {
            for (int k = n; k >= 0; --k) {
                if(k - ci >= 0 && (dp[i][k - ci] || k - ci == 0))
                    dp[i][k] = max(dp[i][k], dp[i][k - ci] + di);
            }
        }
    }
    for (int i = 0; i < n+1; i++) ans = max(ans, dp[m-1][i]);
    cout << ans;
}
