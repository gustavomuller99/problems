#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
ll f(ll x) {
    ll r = 0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == -1) {
            if(i > 0 && a[i-1] != -1) r = max(r, abs(x - a[i-1]));
            if(i < a.size()-1 && a[i+1] != -1) r = max(r, abs(x - a[i+1]));
        } else {
            if(i > 0 && a[i-1] != -1) r = max(r, abs(a[i] - a[i-1]));
            if(i < a.size()-1 && a[i+1] != -1) r = max(r, abs(a[i] - a[i+1]));
        }
    }
    return r;
}
int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        int l = 0, r = 1e9;
        while(l + 2 < r) {
            int m1 = l + (r-l)/3, m2 = r - (r-l)/3;
            ll f1 = f(m1), f2 = f(m2);
            /*cout << l << " " << r << "\n";
            cout << m1 << " " << m2 << "\n";
            cout << f1 << " " << f2 << "\n\n";*/
            if(f1 > f2) l = m1;
            else if (f2 > f1) r = m2;
            else l = m1, r = m2;
        }
        ll d = LLONG_MAX, ans = 0;
        //cout << l << " " << r << "\n";
        for (int i = l; i <= r; ++i) {
            ll diff = f(i);
            if(diff < d) d = diff, ans = i;
        }
        cout << d << " " << ans << "\n";
    }
}
