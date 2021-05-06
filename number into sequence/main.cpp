#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        map<ll, ll> mp;
        ll n, c, h = 0; cin>>n; c = n;
        vector<ll> a, ans;
        for (ll i = 2; i*i <= n; ++i) {
            if(c%i==0) {
                while(c%i==0) {
                    c /= i; a.push_back(i);
                }
            }
        }
        if(c != 1) a.push_back(c);
        for (int i = 0; i < a.size(); ++i) mp[a[i]]++;
        for (int i = 0; i < a.size(); ++i) if(mp[a[i]] > mp[h]) h = a[i];
        for (int i = 0; i < mp[h]; ++i) ans.push_back(h);
        for (int i = 0; i < a.size(); ++i) if(a[i] != h) ans[ans.size()-1] *= a[i];
        cout << ans.size() << "\n";
        for(ll k : ans) cout << k << " "; cout << "\n";
    }
}
