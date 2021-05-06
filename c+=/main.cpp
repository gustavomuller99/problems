#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, n; cin >> a >> b >> n;
        if(b > a) swap(a, b);
        vector<ll> f(100); f[0] = b; f[1] = a;
        int ans = 2;
        while(f[ans-1] <= n) {
            f[ans] = f[ans-1] + f[ans-2];
            ans++;
        }
        cout << ans-2 << "\n";
    }
}
