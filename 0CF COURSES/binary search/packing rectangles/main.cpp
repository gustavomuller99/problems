#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w, h, n;
int f(ll x) { return (x/w)*(x/h) >= n; }
int main() {
    ios::sync_with_stdio(false);
    cin >> w >> h >> n;
    ll l = 0, r = 1;
    while(f(r) != 1) {r *= 2;}
    while(r > l + 1) {
        ll mid = (r + l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}
