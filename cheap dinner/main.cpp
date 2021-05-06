#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> a(4);
    vector<vector<int>> c(4);
    vector<vector<vector<int>>> p(4);
    for (int i = 0; i < 4; ++i) cin>>a[i];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            int x; cin>>x; c[i].push_back(x);
        }
        p[i].resize(a[i]);
    }
    for (int i = 1; i < 4; ++i) {
        int mi; cin>>mi;
        for (int j = 0; j < mi; ++j) {
            int x,y; cin>>x>>y; x--,y--;
            p[i][y].push_back(x);
        }
    }
    for (int i = 1; i < 4; ++i) {
        multiset<int> m;
        for (int j = 0; j < a[i-1]; ++j) if(c[i-1][j] != INT_MAX) m.insert(c[i-1][j]);
        for (int j = 0; j < a[i]; ++j) {
            for (int k = 0; k < p[i][j].size(); ++k) {
                int x = p[i][j][k];
                int cost = c[i-1][x];
                if(cost == INT_MAX) continue;
                m.erase(m.find(cost));
            }
            if(m.empty()) c[i][j] = INT_MAX;
            else c[i][j] = c[i][j] + *m.begin();
            for (int k = 0; k < p[i][j].size(); ++k) {
                int x = p[i][j][k];
                int cost = c[i-1][x];
                if(cost == INT_MAX) continue;
                m.insert(cost);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < a[3]; ++i) {
        ans = min(ans, c[3][i]);
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
