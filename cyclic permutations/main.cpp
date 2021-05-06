#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll MOD = 1e9 + 7;
int main() {
    int n; cin >> n;
    ll f = 1, p = 1;
    for(ll i = 2; i <= n; ++i) {
        f = (f*i) % MOD;
        p = (p*2) % MOD;
    }

    cout << (f + MOD - p) % MOD << "\n";
}
