#include <bits/stdc++.h>
using namespace std;
vector<string> f;
vector<vector<int>> edges;
vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n,m,v=0,e=0;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    f.resize(n);
    edges.resize(n, vector<int> (m));
    pair<int,int> s;
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
        for (int j = 0; j < m; ++j) {
            if(f[i][j]=='#') v++, s = {i,j};
        }
    }
    set<pair<pair<int,int>,pair<int,int>>> sv;
    queue<pair<int,int>> q;
    q.push(s);
    while(!q.empty()) {
        auto r = q.front();
        q.pop();
        f[r.first][r.second] = '+';
        for (int i = 0; i < 4; ++i) {
            if(r.first+d[i].first >= 0 && r.first+d[i].first < n && r.second+d[i].second >= 0 && r.second+d[i].second < m && (f[r.first+d[i].first][r.second+d[i].second] == '#' || f[r.first+d[i].first][r.second+d[i].second] == '+')) {
                if(!sv.count({{r.first,r.second},{r.first+d[i].first,r.second+d[i].second}}) && !sv.count({{r.first+d[i].first,r.second+d[i].second},{r.first,r.second}})) {
                    e++, sv.insert({{r.first, r.second},{r.first+d[i].first, r.second+d[i].second}});
                    edges[r.first][r.second]++, edges[r.first+d[i].first][r.second+d[i].second]++;
                }
                if(f[r.first+d[i].first][r.second+d[i].second] == '#') q.push({r.first+d[i].first, r.second+d[i].second});
            }
        }
    }
    vector<int> edg;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) edg.push_back(edges[i][j]);
    }
    sort(edg.begin(), edg.end(), greater<>());
    for(int x : edg) {
        ans++;
        v--;
        e-=x;
        if(v-e>=2) break;
    }
    cout << ans;
}
