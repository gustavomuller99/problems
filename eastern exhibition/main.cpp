#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; ++i) cin>>x[i]>>y[i];
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll ans = 1;
        if(x.size()%2==0) ans *= x[x.size()/2] - x[x.size()/2 - 1] + 1;
        if(y.size()%2==0) ans *= y[y.size()/2] - y[y.size()/2 - 1] + 1;
        cout << ans << "\n";
    }
}
