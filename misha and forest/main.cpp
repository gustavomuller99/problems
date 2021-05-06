#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> mp;
queue<int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, s; cin >> d >> s;
        if(d == 1) q.push(i);
        mp[i] = {s, d};
    }
    set<pair<int, int>> ans;
    while(!q.empty()) {
        int r = q.front();
        q.pop();
        if(mp[r].second) {
            mp[r].second--;
            mp[mp[r].first].second--;
            ans.insert({r, mp[r].first});
            mp[mp[r].first].first ^= r;
            if (mp[mp[r].first].second == 1) q.push(mp[r].first);
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x.first << " " << x.second << "\n";
}
