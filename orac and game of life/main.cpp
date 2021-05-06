#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
// good cell -> a cell (i,j) that has a neighbour with the same color
// bad cell -> a cell that's alone
// if its a bad cell, find the nearest (bfs) good cell and count the amount of turns to become a good cell
// after that, it changes every turn.
int game[1000][1000] = {0};
int dp[1000][1000] = {0};
int n, m;
int is_good(int i, int j) {
    bool ans = false;
    if(i > 0) ans |= game[i][j] == game[i-1][j];
    if(i < n - 1) ans |= game[i][j] == game[i+1][j];
    if(j < m - 1) ans |= game[i][j] == game[i][j+1];
    if(j > 0) ans |= game[i][j] == game[i][j-1];
    return ans;
}
int bfs(int i, int j) {
    int visited[1000][1000] = {0};
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0,make_pair(i,j)));
    while (!q.empty()) {
        pair<int,pair<int,int>> s = q.front();
        int x = s.second.first, y = s.second.second, d = s.first;
        q.pop();
        if(!visited[x][y]) {
            visited[x][y] = 1;
            if(is_good(x,y)) return d;
            if(x > 0) q.push(make_pair(d+1 ,make_pair(x-1,y)));
            if(x < n - 1) q.push(make_pair(d+1, make_pair(x+1,y)));
            if(y < m - 1) q.push(make_pair(d+1, make_pair(x,y+1)));
            if(y > 0) q.push(make_pair(d+1, make_pair(x,y-1)));
        }
    } return 0;
}
int main() {
    ull t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        string in;
        cin >> in;
        for(int j = 0; j < m; j++) {
            game[i][j] = in[j] == '1';
        }
    }
    for(int k = 0; k < t; k++) {
        ull i, j, p;
        cin >> i >> j >> p;
        i--; j--;
        ull diff = 0;
        if (dp[i][j] != 0) {diff = dp[i][j];}
        else if (!is_good(i, j)) { diff = bfs(i, j); dp[i][j] = diff;}

        if (diff < p && m + n > 2) { p = p - diff + game[i][j]; }
        else p = game[i][j];
        cout << (p & 1 << 0) << endl;
    }
}
