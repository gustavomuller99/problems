#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<pair<ll,int>> a(n);
        for (int i = 0; i < n; ++i) {
            ll x; cin>>x;
            a[i] = {x, i};
        }
        sort(a.begin(), a.end());
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            s += a[i].first;
            if(s >= a[i+1].first) cnt++;
            else cnt = 0;
        }
        set<int> ans;
        for (int i = n-1; cnt >= 0; --i, --cnt) ans.insert(a[i].second);
        cout << ans.size() << "\n";
        for(int k : ans) cout << k + 1 << " "; cout << "\n";
    }
}
