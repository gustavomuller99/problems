#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int a,b,k; cin>>a>>b>>k;
        unsigned long long ans = 0;
        vector<pair<int, int>> p(k);
        map<int,int> m1, m2;
        for (int i = 0; i < k; ++i) {
            int x; cin>>x; m1[x]++;
            p[i].first = x;
        }
        for (int i = 0; i < k; ++i) {
            int x; cin>>x; m2[x]++;
            p[i].second = x;
        }
        for(auto pair : p) {
            ans += k - m1[pair.first] - m2[pair.second] + 1;
        }
        cout << ans/2 << "\n";
    }
}
