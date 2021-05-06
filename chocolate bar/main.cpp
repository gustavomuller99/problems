#include <bits/stdc++.h>
using namespace std;
int dp[31][31][51];
int d(int x, int y, int k) {
    if(!k || x*y == k) return 0;
    if(dp[x][y][k]) return dp[x][y][k];
    int r = 1e9;
    for (int i = 1; i <= x/2; ++i) {
        for (int j = 0; j <= k; ++j) {
            r = min(r, y*y + d(x-i, y, k-j) + d(i, y, j));
        }
    }
    for (int i = 1; i <= y/2; ++i) {
        for (int j = 0; j <= k; ++j) {
            r = min(r, x*x + d(x, y-i, k-j) + d(x, i, j));
        }
    }
    return dp[x][y][k] = r;
}
int main() {
    memset(dp, 0, sizeof(dp));
    int t; cin >> t; while(t--) {
        int a,b,k; cin>>a>>b>>k;
        cout << d(a,b,k) << "\n";
    }
}
