#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll unsigned long long
int n,m,k;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        cin>>n>>m>>k;
        vector<vector<ll>> c(n+1, vector<ll>(m+1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, m); ++j) {
                if(j == 0 || j == i) c[i][j] = 1;
                else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
            }
        }
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        sort(a.begin(), a.end());
        int l = 0; ll ans = 0;
        for (int i = 0; i < n; ++i) {
            while(a[i] - a[l] > k) l++;
            if(i-l >= m-1) ans = (ans + c[i-l][m-1]) % MOD;
        }
        cout << ans << "\n";
    }
}
