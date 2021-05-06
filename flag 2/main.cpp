#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin>>n>>m;
    vector<string> a(n);
    pair<int, pair<int,int>> d[n][26][26];
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                int c = 0;
                if(j == k) continue;
                for (int l = 0; l < m; ++l) {
                    if(l % 2 && a[i][l] - 'a' != k) c++;
                    if(l % 2 == 0 && a[i][l] - 'a' != j) c++;
                }
                if(i) for (int l = 0; l < 26; ++l) {
                    for (int o = 0; o < 26; ++o) {
                        if(l == o) continue;
                        if(l == j || o == k) continue;
                        if(d[i][j][k].first == -1 || d[i-1][l][o].first + c < d[i][j][k].first) d[i][j][k] = {d[i-1][l][o].first + c, {l,o}};
                    }
                }
                else d[i][j][k].first = c;
            }
        }
    }
    int ans = INT_MAX;
    vector<string> pr(n);
    pair<int,int> p;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(i == j) continue;
            if(d[n-1][i][j].first < ans) ans = d[n-1][i][j].first, p = {i,j};
        }
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if(j%2==0) pr[i].push_back(p.first + 'a');
            else pr[i].push_back(p.second + 'a');
        }
        p = d[i][p.first][p.second].second;
    }
    cout << ans << "\n";
    for(string s : pr) cout << s << "\n";
}
