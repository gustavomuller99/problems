#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; int k, a; cin>>s>>k>>a; k++;
    int dp[s.size()][k][26]; int c[26][26]; memset(dp, -10000000, sizeof(dp)); memset(c, 0, sizeof(c));
    for (int i = 0; i < a; ++i) {
        char x,y; int z; cin>>x>>y>>z;
        x-='a',y-='a'; c[x][y] = z;
    }

    for (int i = 0; i < s.size(); ++i) s[i] -= 'a';
    for (int i = 0; i < k; ++i) for (int j = 0; j < 26; ++j) dp[0][i][j] = 0;

    for (int i = 1; i < s.size(); ++i) {
        dp[i][0][s[i]] = c[s[i-1]][s[i]] + dp[i-1][0][s[i-1]];
        if(k > 1) for (int l = 0; l < 26; ++l) {
            dp[i][1][s[i]] = max(dp[i][1][s[i]], dp[i-1][1][l] + c[l][s[i]]);
            if(l != s[i]) dp[i][1][l] = dp[i-1][0][s[i-1]] + c[s[i-1]][l];
        }
        for (int j = 2; j < k; ++j) {
            for (int l = 0; l < 26; ++l) {
                for (int n = 0; n < 26; ++n) {
                    if(l == s[i]) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][n] + c[n][l]);
                    else dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][n] + c[n][l]);
                }
            }
        }

    }

    /*for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            for (int l = 0; l < 26; ++l) {
                cout << dp[i][j][l] << " ";
            } cout << "\n";
        } cout << "\n\n";
    }*/

    int ans = INT_MIN;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans = max(ans, dp[s.size()-1][i][j]);
        }
    }
    cout << ans;

}
