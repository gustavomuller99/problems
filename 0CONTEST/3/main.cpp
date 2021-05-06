#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n, m, diff = 0; cin>>n>>m;
        vector<int> a(n),b(n),c(m);
        map<int, vector<int>> mp;
        map<int, vector<int>> mp2;
        for (int i = 0; i < n; ++i) cin>>a[i];
        for (int i = 0; i < n; ++i) cin>>b[i];
        for (int i = 0; i < m; ++i) cin>>c[i];
        for (int i = 0; i < n; ++i) {
            if(a[i] != b[i]) mp[b[i]].push_back(i),diff++;
            else mp2[b[i]].push_back(i);
        }
        if(diff > m) cout << "NO\n";
        else {
            int pos = -1;
            bool p = true;
            vector<int> ans;
            for (int i = m-1; i >= 0; --i) {
                int cl = c[i];
                if(!mp[cl].empty()) {
                    ans.push_back(mp[cl].back());
                    pos = mp[cl].back(); mp[cl].pop_back();
                }
                else {
                    if(!mp2[cl].empty()) ans.push_back(mp2[cl][0]), pos = mp2[cl][0];
                    else if(pos != -1) ans.push_back(pos);
                    else p = false;
                }
            }
            for (int i = 1; i <= n; ++i) if(!mp[i].empty()) p = false;
            if(p) {
                cout << "YES\n";
                for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
                    cout << *i+1 << " ";
                } cout << "\n";
            } else cout << "NO\n";
        }
    }
}
