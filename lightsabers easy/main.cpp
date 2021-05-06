#include <bits/stdc++.h>
using namespace std;
vector<int> c, a;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;cin>>n>>m;
    c.resize(n); a.resize(m);
    for (int i = 0; i < n; ++i) cin>>c[i];
    for (int i = 0; i < m; ++i) cin>>a[i];
    int ok = 0, f = 0, l = 0;
    map<int, pair<int,vector<int>>> mp;
    vector<int> am(m);
    for (int i = 0; i < m; ++i) if(am[i] == a[i]) ok++;
    for (int i = 0; i < n; ++i) {
        int cc = c[i] - 1;
        mp[cc].second.push_back(i);
        am[cc]++;
        if(am[cc] == a[cc]) {
            ok++;
            if(ok == m) f = 1;
        } else if (am[cc] > a[cc]) {
            int index = mp[cc].first;
            while(l <= mp[cc].second[index]) {
                int cd = c[l] - 1;
                if(am[cd] == a[cd]) ok--;
                am[cd]--;
                mp[cd].first++;
                l++;
            }
        }
    }
    if(f) cout << "YES";
    else cout << "NO";
}
