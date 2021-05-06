#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k;
vector<int> a;

bool f(ll x) {
    ll o=0, e=0;
    for (int i : a) {
        if((e % 2 == 0 && i <= x) || e % 2 == 1) e++;
        if((o % 2 == 1 && i <= x) || o % 2 == 0) o++;
    }
    return o >= k || e >= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = 1;
    while(!f(r)) r *= 2;
    while(r > l + 1) {
        ll mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}
