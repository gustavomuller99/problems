#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<ll, pair<int, int>> mp;
    set<pair<ll, pair<int, int>>> pos;
    vector<ll> a(n), p(n + 1);
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll k; cin >> k;
        a[i-1] = k;
        p[i] = p[i-1] + (k > 0 ? k : 0);
        mp[k] = {min((mp[k].first == 0 ? INT_MAX : mp[k].first), i), max((mp[k].second == 0 ? INT_MIN : mp[k].second), i)};
    }
    int l, r, c = 0;
    ll s = LLONG_MIN;
    for(int k : a) {
        if(mp[k].first != 0 && mp[k].second != 0 && mp[k].first != mp[k].second) {
            int lx = mp[k].first - 1, rx = mp[k].second - 1;
            lx++, rx--;
            if(s <= a[lx-1] + a[rx+1] + p[rx+1] - p[lx]) {
                s = a[lx-1] + a[rx+1] + p[rx+1] - p[lx];
                l = mp[k].first - 1;
                r = mp[k].second - 1;
            }
        }
    }
    for (int i = l+1; i < r; ++i) if(a[i] < 0) c++;
    cout << s << " " << l + c + n - (r+1) << "\n";
    for (int i = 0; i < l; ++i) cout << i+1 << " ";
    for (int i = l+1; i < r; ++i) if(a[i] < 0) cout << i+1 << " ";
    for (int i = r+1; i < n; ++i) cout << i+1 << " ";
}
