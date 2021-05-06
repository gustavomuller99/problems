#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c;
bool f(ll x) {
    ll c_a = a, c_b = b, c_c = c;
    x *= 7; x--;
    c_a -= x/7, c_b -= x/7, c_c -= x/7, x -= x/7;
    if(c_a <= 0 || c_b <= 0 || c_c <= 0) return false;
    return x <= (c_a-1) + (c_b-1) + (c_c-1);
}
int main() {
    int t; cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        ll l = 1, r = 1e8;
        while(l + 1 < r) {
           ll mid = (l+r) / 2;
           if(f(mid)) l = mid;
           else r = mid;
        }
        l *= 7; l--;
        a -= l/7, b -= l/7, c -= l/7; l -= l/7;
        if(a <= 0 || b <= 0 || c <= 0) cout << "NO\n";
        else if(l == (a - 1) + (b - 1) + (c - 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}
