#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<pair<int,int>> ans;
        int l = n, r = n;
        while(r > 2) {
            l = floor(sqrt(l)) + 1;
            for (int i = r-1; i > l; --i) {
                ans.emplace_back(i, r);
            }
            ans.emplace_back(r, l);
            ans.emplace_back(r, l);
            r = l;
        }
        cout << ans.size() << "\n";
        for(auto k : ans) cout << k.first << " " << k.second << "\n";
    }
}
