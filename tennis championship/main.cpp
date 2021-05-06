#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n; cin >> n;
    vector<ll> f(2);
    f[0] = 1; f[1] = 2;
    while(true) {
        f.push_back(f[f.size() - 1] + f[f.size() - 2]);
        if(f[f.size() - 1] > n) break;
    }
    cout << f.size() - 2;
}
