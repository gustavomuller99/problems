#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        bool ans = true;
        map<ll, int> m;
        vector<ll> a;
        for (int i = 0; i < 2*n; ++i) {
            ll x; cin>>x; m[x]++;
        }
        ll s = 0;
        n = 2*n;
        for (auto i = m.rbegin(); i != m.rend(); ++i) {
            ll k = i->first;
            k -= 2*s;
            if(k % n != 0 || k <= 0 || i->second != 2) { ans = false; break; }
            k = k/n;
            s += k;
            n-=2;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}