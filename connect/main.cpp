#include <bits/stdc++.h>
using namespace std;
int n;
string grid[50];
vector<pair<int,int>> bfs(int r, int c) {
    vector<pair<int,int>> s;
    int visited[50][50] = {0};
    queue<pair<int,int>> _s;
    _s.push(make_pair(r,c));
    while(!_s.empty()) {
        pair<int,int> p = _s.front();
        s.push_back(p);
        _s.pop();
        visited[p.first][p.second] = 1;
        if(p.first > 0) {
            if(!visited[p.first-1][p.second] && grid[p.first-1][p.second] != '1') _s.push(make_pair(p.first-1, p.second));
        }
        if(p.first < n-1) {
            if(!visited[p.first+1][p.second] && grid[p.first+1][p.second] != '1') _s.push(make_pair(p.first+1, p.second));
        }
        if(p.second > 0) {
            if(!visited[p.first][p.second-1] && grid[p.first][p.second-1] != '1') _s.push(make_pair(p.first, p.second-1));
        }
        if(p.second < n-1) {
            if(!visited[p.first][p.second+1] && grid[p.first][p.second+1] != '1') _s.push(make_pair(p.first, p.second+1));
        }
    }
    return s;
}
int main() {
    cin >> n;
    int rs, rt, cs, ct;
    cin >> rs >> cs;
    cin >> rt >> ct;
    rs--; cs--; rt--; ct--;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<pair<int,int>> s;
    vector<pair<int,int>> d;
    s = bfs(rs, cs);
    if(find(s.begin(), s.end(), make_pair(rt,ct)) != s.end()) {
        cout << "0" << endl;
        return 0;
    }
    d = bfs(rt, ct);
    int min = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < d.size(); j++) {
            int price = pow(s[i].first - d[j].first, 2) + pow(s[i].second - d[j].second, 2);
            min = (price > min) ? min : price;
        }
    }
    cout << min << endl;
    return 0;
}
