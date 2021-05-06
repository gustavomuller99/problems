#include <bits/stdc++.h>
using namespace std;
#define ll long long
int k;
vector<ll> c;
bool f(ll x) {
    ll b = c[0];
    int v = 1;
    for (int i = 1; i < c.size(); ++i) {
        if(c[i] - b >= x) {
            v++;
            b = c[i];
        }
    }
    return v >= k;
}
int main() {
    int n; cin >> n >> k;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    ll l = 0, r = 1;
    while(f(r)) r*= 2;
    while(r > l + 1) {
        ll mid = (l + r) / 2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}
