#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        vector<int> a(2*n);
        bool ps = false;
        for (int i = 0; i < 2*n; ++i) cin>>a[i];
        sort(a.begin(), a.end(), greater<>());
        for (int i = 1; i < a.size(); ++i) {
            vector<pair<int,int>> ans; ans.emplace_back(a[0], a[i]);
            multiset<int, greater<>> m;
            for (int j = 1; j < a.size(); ++j) if(j != i) m.insert(a[j]);
            int s = a[0];
            bool psi = true;
            while(!m.empty()) {
                int f = *m.begin(); m.erase(m.begin());
                if(!m.count(s - f)) { psi = false; break; }
                m.erase(m.find(s - f));
                ans.emplace_back(f, s - f);
                s = f;
            }
            if(psi) {
                ps = true;
                cout << "YES\n" << a[0] + a[i] << "\n";
                for(auto k : ans) cout << k.first << " " << k.second << "\n";
                break;
            }
        }
        if(!ps) cout << "NO\n";
    }
}
