#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; cin>>n;
    ll ans = ULLONG_MAX;
    vector<ll> s(n),c(n);
    vector<vector<ll>> d(3, vector<ll>(n, ULLONG_MAX));
    for (int i = 0; i < n; ++i) cin>>s[i];
    for (int i = 0; i < n; ++i) cin>>c[i];
    for (int i = 0; i < n; ++i) {
        d[0][i] = c[i];
        for (int j = 0; j < i; ++j) {
            if(s[j] < s[i]) {
                if(d[0][j] != ULLONG_MAX) d[1][i] = min(d[1][i], d[0][j] + c[i]);
                if(d[1][j] != ULLONG_MAX) d[2][i] = min(d[2][i], d[1][j] + c[i]);
            }
        }
        ans = min(ans, d[2][i]);
    }
    if(ans == ULLONG_MAX) cout << -1;
    else cout << ans;
}
