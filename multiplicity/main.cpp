#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll MOD = 1e9+7;
vector<int> a;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        vector<int> d;
        for (int j = 1; j*j <= a[i]; ++j) {
            if(a[i] % j == 0) { d.push_back(j - 1); if(j != a[i]/j) d.push_back(a[i]/j - 1); }
        }
        sort(d.begin(), d.end(), greater<>());
        for(int k : d) { if(k > 0 && k < n) dp[k] += dp[k-1], dp[k] %= MOD; }
        dp[0]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) { ans += dp[i]; }
    cout << ans%MOD << "\n";
}
