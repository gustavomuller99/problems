#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, ans = 0; cin>>n;
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; ++i) cin >> a[i], mp[a[i]]++;
        for(auto x : mp) {
            ans++;
            if(x.second > 1) mp[x.first + 1]++;
        }
        cout << ans << "\n";
    }
}
