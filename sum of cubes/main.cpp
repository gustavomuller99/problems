#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    set<ll> c;
    for (ll i = 1; i <= 10000; ++i) c.insert(i*i*i);
    int t; cin>>t; while(t--) {
        ll x; cin>>x; bool p = false;
        for (ll i = 1; i*i*i <= x; ++i) {
            if(c.count(x - i*i*i)) { p = true; break; }
        }
        if(p) cout << "YES\n";
        else cout << "NO\n";
    }
}