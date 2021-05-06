#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n; int k; cin >> n >> k;
    multiset<ll> p;
    int i = 0;
    while(1 << i <= n) {
        if(n & 1 << i) p.insert(1 << i);
        i++;
    }
    while(p.size() < k && *p.rbegin() != 1) {
        ll x = *p.rbegin();
        auto it = p.end();
        it--;
        p.erase(it);
        p.insert(x/2); p.insert(x/2);
    }
    if(p.size() != k) cout << "NO\n";
    else {
        cout << "YES\n";
        for(ll x : p) cout << x << " ";
    } cout << "\n";
}
