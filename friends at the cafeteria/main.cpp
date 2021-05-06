#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, ans=0; cin>>n>>m;
    vector<pair<int,int>> a(20000003);
    for (int i = 0; i < n; ++i) {
        int l,t; cin>>l>>t;
        a[l].first++, a[l+t].second++;
    }
    int l = 1, r = 1, cur = 0;
    for (r = 1; r <= m+1; ++r) cur += a[r].first; r--;
    ans = cur;
    while(r < a.size()) {
        r++; l++;
        cur += a[r].first;
        cur -= a[l-1].second;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
