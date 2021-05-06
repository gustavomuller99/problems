#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int n; cin>>n;
    vector<ll> b(n-1);
    for (int i = 0; i < n-1; ++i) cin>>b[i];
    vector<vector<ll>> d(n, vector<ll>(4));
    d[0][0] = d[0][1] = 0;
    for (int i = 1; i < n; ++i) {
        if(b[i-1] > 1) d[i][0] = d[i-1][0] + (b[i-1] - b[i-1] % 2);
        d[i][1] = max(d[i-1][0], d[i-1][1]) + b[i-1] - (b[i-1] % 2 == 0);
    }
    d[n-1][0] = d[n-1][1] = 0;
    for (int i = n-2; i >= 0; --i) {
        if(b[i] > 1) d[i][2] = d[i+1][2] + (b[i] - b[i] % 2);
        d[i][3] = max(d[i+1][2], d[i+1][3]) + b[i] - (b[i] % 2 == 0);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, d[i][0] + d[i][2]);
        ans = max(ans, d[i][0] + d[i][3]);
        ans = max(ans, d[i][1] + d[i][2]);
    }
    cout << ans << "\n";
}
