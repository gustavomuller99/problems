#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,k,p; cin>>n>>k>>p;
    vector<ll> e, o;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        if(x%2) o.push_back(x);
        else e.push_back(x);
    }
    if((o.size() - (k-p)) % 2 == 1 || ((o.size() - (k-p))/2) + e.size() < p || o.size() < k-p) cout << "NO";
    else {
        cout << "YES" << "\n";
        vector<vector<ll>> ans(k);
        for (int i = 0; i < k-p; ++i) {
            ans[i].push_back(o[o.size() - 1]);
            o.pop_back();
        }
        for (int i = k-p; i < k; ++i) {
            if(!e.empty()) {
                ans[i].push_back(e[e.size() - 1]);
                e.pop_back();
            } else {
                ans[i].push_back(o[o.size() - 1]); o.pop_back();
                ans[i].push_back(o[o.size() - 1]); o.pop_back();
            }
        }
        for(ll x : o) ans[0].push_back(x);
        for(ll x : e) ans[0].push_back(x);
        for(const auto& x : ans) {
            cout << x.size() << " ";
            for(auto y : x) cout << y << " ";
            cout << "\n";
        }
    }
}
