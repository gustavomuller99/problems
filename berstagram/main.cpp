#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> q(n + 1);
    vector<int> pos(n + 1);
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; ++i) { pos[i] = q[i] = i; mp[i] = {i, i}; }
    for (int i = 0; i < m; ++i) {
        int s; cin >> s;
        if(pos[s] != 1) {
            swap(q[pos[s]], q[pos[s] - 1]);
            pos[s]--; pos[q[pos[s] + 1]]++;
            if(pos[s] < mp[s].first) mp[s].first = pos[s];
            if(pos[q[pos[s] + 1]] > mp[q[pos[s] + 1]].second) mp[q[pos[s] + 1]].second = pos[q[pos[s] + 1]];
        }
    }
    for (int i = 1; i <= n; ++i) cout << mp[i].first << " " << mp[i].second << "\n";
}
