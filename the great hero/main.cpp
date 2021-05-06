#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        ll a,b,n; cin>>a>>b>>n;
        bool p = true;
        vector<ll> ma(n), mb(n);
        vector<pair<ll, int>>l(n);
        for (int i = 0; i < n; ++i) cin>>ma[i];
        for (int i = 0; i < n; ++i) cin>>mb[i];
        for (int i = 0; i < n; ++i) {
            ll f1 = (mb[i] - 1) / a + 1;
            l[i] = {f1*ma[i], i};
        }
        sort(l.begin(), l.end());
        int i;
        for (i = 0; i < n; ++i) {
            b -= l[i].first;
            if(b <= 0) {
                b += l[i].first;
                ll mh = mb[l[i].second], md = ma[l[i].second];
                ll f1 = (mh - 1) / a + 1;
                ll f2 = (b - 1) / md + 1;
                if(f2 < f1) p = false;
                break;
            }
        }
        if(i < n-1 || !p) cout << "NO\n";
        else cout << "YES\n";
    }
}