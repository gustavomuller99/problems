#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,m,k;
bool f(ll x) {
    ll ac = 0;
    for (int i = 1; i <= n; ++i) {
        ac += min((ll) m, x/i - (x%i9==0));
    }
    return ac < k;
}
int main() {
    cin>>n>>m>>k;
    if(m > n) swap(m, n);
    ll l = 1, r = m*n+1;
    while(l + 1 < r) {
       ll mid = (l+r)/2;
       if(f(mid)) l = mid;
       else r = mid;
    }
    cout << l;
}
