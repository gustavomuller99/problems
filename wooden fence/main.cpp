#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, l; cin>>n>>l;
    ll d[l+1][n][2]; memset(d, 0, sizeof(d));
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
    for (int i = 1; i <= l; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i - a[j].first == 0) d[i][j][0]++;
            if(a[j].first != a[j].second && i - a[j].second == 0) d[i][j][1]++;
            for (int k = 0; k < n; ++k) {
                if(j == k) continue;
                if(a[j].first == a[k].first && i - a[j].first > 0) d[i][j][0] = (d[i][j][0] + d[i-a[j].first][k][1]) % MOD;
                if(a[j].first == a[k].second && i - a[j].first > 0) d[i][j][0] = (d[i][j][0] + d[i-a[j].first][k][0]) % MOD;
                if(a[j].first != a[j].second) {
                    if(a[j].second == a[k].first && i - a[j].second > 0) d[i][j][1] = (d[i][j][1] + d[i-a[j].second][k][1]) % MOD;
                    if(a[j].second == a[k].second && i - a[j].second > 0) d[i][j][1] = (d[i][j][1] + d[i-a[j].second][k][0]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = ((ans + d[l][i][1]) % MOD + d[l][i][0]) % MOD;
    cout << ans;
}
