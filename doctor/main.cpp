#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    ll n, k, sum=0, c; cin>>n>>k;
    vector<ll> a(n); map<ll, int> mp;
    for (int i = 0; i < n; ++i) cin>>a[i], sum+=a[i];
    if(sum < k) cout << -1;
    else if(sum == k) cout << "\n";
    else {
        c = n; ll prev = 0, sub;
        vector<pair<ll, int>> rem;
        vector<int> ans;
        for (int i = 0; i < n; ++i) mp[a[i]]++;
        for (auto x : mp) {
            k -= c*(x.first-prev);
            c -= x.second;
            if(k < 0) {
                c += x.second;
                k += c*(x.first-prev);
                sub = prev;
                break;
            }
            prev = x.first;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = max(0ll, a[i] - sub);
            if(a[i]) rem.emplace_back(i, a[i]);
        }
        for (int i = 0; i < rem.size(); ++i) rem[i].second -= k / rem.size();
        ll r = rem.size(); k %= r;
        ll i = k;
        for (int j = 0; j < i; ++j) rem[j].second--;
        do {
            if(rem[i%r].second) ans.push_back(rem[i%r].first), rem[i%r].second--;
            i = (i+1)%r;
        } while(i != k);
        for(int x : ans) cout << x + 1 << " ";
    }
}
