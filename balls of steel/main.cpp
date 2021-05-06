#include <bits/stdc++.h>
using namespace std;
bool d(pair<int,int> a, pair<int,int> b, int k) {
    return abs(a.first-b.first) + abs(a.second-b.second) <= k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;cin>>t;while(t--) {
        int n,k; cin>>n>>k;
        vector<pair<int,int>> p(n);
        bool ans = false;
        for (int i = 0; i < n; ++i) cin>>p[i].first>>p[i].second;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if(d(p[i],p[j],k)) cnt++;
            }
            if(cnt==p.size()) ans = true;
        }
        if(ans) cout << 1 << "\n";
        else cout << -1 << "\n";
    }
}
