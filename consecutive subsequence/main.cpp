#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, int> dp;
vector<ll> a;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int h = 0; ll p = 0;
    for (int i = 0; i < n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if(dp[a[i]] > h) {
           h = dp[a[i]];
           p = a[i];
        }
    }
    cout << h << "\n";
    vector<int> ans;
    for (int i = n; i >= 0; --i) {
        if(a[i] == p) { ans.push_back(i + 1); p--; }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
}
