#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int x, y;
bool f(ll t) {
    t -= min(x, y);
    ll s = t/x + t/y + 1;
    return s >= n;
}
int main() {
    cin >> n >> x >> y;
    if(n==1) cout << min(x, y);
    else {
        ll l = 0, r = 1;
        while (!f(r)) r *= 2;
        while (r > l + 1) {
            ll mid = (r + l) / 2;
            if (f(mid)) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}
