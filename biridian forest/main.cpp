#include <queue>
#include <iostream>
using namespace std;
int r, c, ans = 0;
string f[1005];
pair<int,int> e, s;
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> f[i];
        for(int j = 0; j < f[i].size(); j++) {
            if(f[i][j] == 'S') s = {i, j};
            else if(f[i][j] == 'E') e = {i, j};
        }
    }
    queue<pair<int,int>> q;
    q.push({e});
    while(!q.empty()) {
        auto rt = q.front();
        q.pop();
        if((f[rt.first][rt.second] >= '0' && f[rt.first][rt.second] <= '9')) ans += f[rt.first][rt.second]-'0';
        else if((rt.first == s.first && rt.second == s.second)) break;
        f[rt.first][rt.second] = '$';
        if(rt.first > 0 && f[rt.first - 1][rt.second] != '$' && f[rt.first - 1][rt.second] != 'T') q.push({rt.first - 1, rt.second});
        if(rt.first < r - 1 && f[rt.first + 1][rt.second] != '$' && f[rt.first + 1][rt.second] != 'T') q.push({rt.first + 1, rt.second});
        if(rt.second > 0 && f[rt.first][rt.second - 1] != '$' && f[rt.first][rt.second - 1] != 'T') q.push({rt.first, rt.second - 1});
        if(rt.second < c - 1 && f[rt.first][rt.second + 1] != '$' && f[rt.first][rt.second + 1] != 'T') q.push({rt.first, rt.second + 1});
    }
    while(!q.empty()) {
        auto rt = q.front();
        q.pop();
        if((f[rt.first][rt.second] >= '0' && f[rt.first][rt.second] <= '9')) ans += f[rt.first][rt.second]-'0';
    }
    cout << ans << "\n";
}
