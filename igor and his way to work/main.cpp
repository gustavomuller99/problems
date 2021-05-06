#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin>>n>>m;
    pair<int, int> s, t;
    vector<string> g(n);
    int p[n][m]; memset(p, 0, sizeof(p));
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if(g[i][j] == 'S') s = {i,j};
            if(g[i][j] == 'T') t = {i,j};
        }
    }
    for (int i = s.first; i < n; ++i) {
        if(g[i][s.second] == '*') break;
        p[i][s.second] = 1;
        for (int j = s.second+1; j < m; ++j) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
        for (int j = s.second-1; j >= 0; --j) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
    }
    for (int i = s.first; i >= 0; --i) {
        if(g[i][s.second] == '*') break;
        p[i][s.second] = 1;
        for (int j = s.second+1; j < m; ++j) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
        for (int j = s.second-1; j >= 0; --j) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
    }
    for (int j = s.second; j < m; ++j) {
        if(g[s.first][j] == '*') break;
        p[s.first][j] = 1;
        for (int i = s.first+1; i < n; ++i) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
        for (int i = s.first-1; i >= 0; --i) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
    }
    for (int j = s.second; j >= 0; --j) {
        if(g[s.first][j] == '*') break;
        p[s.first][j] = 1;
        for (int i = s.first+1; i < n; ++i) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
        for (int i = s.first-1; i >= 0; --i) {
            if(g[i][j] == '*') break;
            p[i][j] = 1;
        }
    }
    bool ans = false;
    for (int i = t.first; i < n && g[i][t.second] != '*'; ++i) if(p[i][t.second]) ans = true;
    for (int i = t.first; i >= 0 && g[i][t.second] != '*'; --i) if(p[i][t.second]) ans = true;
    for (int j = t.second; j < m && g[t.first][j] != '*'; j++) if(p[t.first][j]) ans = true;
    for (int j = t.second; j >= 0 && g[t.first][j] != '*'; j--) if(p[t.first][j]) ans = true;
    cout << (ans ? "YES" : "NO") << "\n";
}
