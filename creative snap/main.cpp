#include <bits/stdc++.h>
using namespace std;
vector<int> avengers;
#define ll unsigned long long
ll n, k, a, b, pos;
ll solve(ll l, ll h) {
    ll i = lower_bound(avengers.begin(), avengers.end(), l) - avengers.begin();
    ll j = upper_bound(avengers.begin(), avengers.end(), h) - avengers.begin();
    ll mid = (l + h) / 2;
    ll power;
    ll x = j-i;
    if(x) {
        power = b * x * (h-l+1);
    } else power = a;
    if(l == h || x == 0) return power;
    else return min(power, solve(l, mid) + solve(mid+1, h));
}
int main() {
    cin>>n>>k>>a>>b;
    for (ll i = 0; i < k; ++i) {
        cin>>pos;
        avengers.push_back(pos);
    }
    sort(avengers.begin(), avengers.end());
    cout << solve(1, pow(2, n)) << endl;
}
