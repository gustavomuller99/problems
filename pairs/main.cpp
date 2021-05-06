#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,l,r; cin>>n;
        vector<int> b(n), c(2*n+1), d;
        set<int> f, s, p;
        for (int i = 0; i < n; ++i) cin>>b[i], c[b[i]] = 1, s.insert(b[i]);
        for (int i = 1; i <= 2*n; ++i) if(!c[i]) f.insert(i), d.push_back(i);
        p = f; int cnt = 0;
        for (int i = 0; i < n; ++i) {
            auto pp = p.upper_bound(b[i]);
            if(pp != p.end()) cnt++, p.erase(pp);
        }
        l = n - cnt;
        p = s; cnt = 0;
        for (int i = 0; i < n; ++i) {
            auto pp = p.upper_bound(d[i]);
            if(pp != p.end()) cnt++, p.erase(pp);
        }
        r = cnt;
        cout << max(l, r) - min(l, r) + 1 << "\n";
    }
}
