#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    vector<string> g(n);
    vector<vector<pair<int,int>>> p(n, vector<pair<int,int>> (m));
    vector<vector<int>> v(n, vector<int> (m));
    pair<int,int> f;
    string path;
    for (int i = 0; i < n; ++i) {
        cin>>g[i];
        for (int j = 0; j < m; ++j) if(g[i][j] == 'F') f = {i,j};
    }
    queue<pair<int,int>> q;
    q.push({0,0}); v[0][0] = 1;
    while(!q.empty()) {
        auto r = q.front(); q.pop(); int x = r.first, y = r.second;
        if(x > 0 && !v[x-1][y] && g[x-1][y] != '*') v[x-1][y] = 1, p[x-1][y] = {1,0}, q.push({x-1,y});
        if(x < n-1 && !v[x+1][y] && g[x+1][y] != '*') v[x+1][y] = 1, p[x+1][y] = {-1,0}, q.push({x+1,y});
        if(y > 0 && !v[x][y-1] && g[x][y-1] != '*') v[x][y-1] = 1, p[x][y-1] = {0,1}, q.push({x,y-1});
        if(y < m-1 && !v[x][y+1] && g[x][y+1] != '*') v[x][y+1] = 1, p[x][y+1] = {0,-1}, q.push({x,y+1});
    }
    while(f.first != 0 || f.second != 0) {
        if(p[f.first][f.second].first == 1) path.push_back('U');
        else if(p[f.first][f.second].first == -1) path.push_back('D');
        else if(p[f.first][f.second].second == 1) path.push_back('L');
        else path.push_back('R');
        f = {f.first + p[f.first][f.second].first, f.second + p[f.first][f.second].second};
    }
    int sx = 0, sy = 0;
    f = {1,1};
    for (int i = path.size()-1; i >= 0; --i) {
        if(sx == 0 && path[i] == 'R') {
            pair<int,int> pos;
            cout << "R" << "\n"; cout.flush(); cin >> pos.first >> pos.second;
            if(pos.first == f.first && pos.second == f.second + 1) {
                sx = 1;
                cout << "L" << "\n"; cout.flush(); cin >> f.first >> f.second;
            } else sx = 2;
        }
        if(sy == 0 && path[i] == 'D') {
            pair<int,int> pos;
            cout << "D" << "\n"; cout.flush(); cin >> pos.first >> pos.second;
            if(pos.first == f.first + 1 && pos.second == f.second) {
                sy = 1;
                cout << "U" << "\n"; cout.flush(); cin >> f.first >> f.second;
            } else sy = 2;
        }
        if(path[i] == 'R') cout << (sx == 2 ? 'L' : 'R') << "\n";
        else if(path[i] == 'L') cout << (sx == 2 ? 'R' : 'L') << "\n";
        else if(path[i] == 'U') cout << (sy == 2 ? 'D' : 'U') << "\n";
        else if(path[i] == 'D') cout << (sy == 2 ? 'U' : 'D') << "\n";
        cout.flush();
        cin >> f.first >> f.second;
    }
}
