#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    map<int, pair<int, int>> mp;
    vector<bool> a(n);
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        int p; cin >> p; p--;
        if(a[p]) {
            mp[p] = {mp[p].first, i};
        } else {
            mp[p] = {i, i};
            a[p] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!a[i]) ans += 3 - (i == 0 || i == n - 1);
        else {
            if(i > 0) ans += (!a[i-1] || mp[i-1].second < mp[i].first);
            if(i < n - 1) ans += (!a[i+1] || mp[i+1].second < mp[i].first);
        }
    }
    cout << ans << "\n";
}
