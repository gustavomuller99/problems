#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        ll n,m,s=0,ans=INT_MAX; cin>>n>>m;
        vector<ll> in, a, b;
        for (int i = 0; i < n; ++i) {
            ll x; cin>>x; in.push_back(x);
            s += x;
        }
        for (int i = 0; i < n; ++i) {
            int c; cin>>c;
            if(c == 2) a.push_back(in[i]);
            else b.push_back(in[i]);
        }
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        if(s < m) cout << -1 << "\n";
        else {
            ll l = 0, r = 0, c = 0, mem = 0;
            for (r = 0; r < b.size(); ++r) c++,mem+=b[r]; r--;
            if(mem >= m) ans = min(ans, c);
            while(r >= -1) {
                while(mem < m && l < a.size()) {
                    mem += a[l]; l++; c+=2;
                }
                if(mem >= m) ans = min(ans, c);
                if(r >= 0) mem -= b[r], c--;
                r--;
            }
            cout << ans << "\n";
        }
    }
}
