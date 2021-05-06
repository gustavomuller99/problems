#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, s1 = 0, s2 = 0, ans = INT_MAX; cin>>n;
        map<ll, int> m;
        for (int i = 0; i < n; ++i) {
            ll x; cin>>x; m[x]++;
        }
        vector<int> a;
        for(auto k : m) a.push_back(k.second);
        sort(a.begin(), a.end());
        for (int i = a.size()-1; i >= 0; --i) s1 += a[i] - a[0];
        for (int i = 0; i < a.size(); ++i) {
            ans = min(ans, s1 + s2);
            s2 += a[i];
            s1 -= (a[i+1] - a[i]) * (a.size()-i-1);
        }
        cout << ans << "\n";
    }
}
