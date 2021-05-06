#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<ll> a(n);
        vector<vector<ll>> d(3, vector<ll> (n));
        for (int i = 0; i < n; ++i) cin>>a[i];
        d[0][0] = d[2][0] = a[0];
        d[1][0] = 0;
        for (int i = 1; i < n; ++i) {
            d[0][i] = d[0][i-1] + (i%2==0 ? a[i] : 0);
            d[1][i] = (i>1 ? max(d[0][i-2], d[1][i-2]) : 0) + (i%2==0 ? a[i-1] : a[i]);
            d[2][i] = max(d[1][i-1], d[2][i-1]) + (i%2==0 ? a[i] : 0);
        }
        cout << max(d[0][n-1], max(d[1][n-1], d[2][n-1])) << "\n";
    }
}
