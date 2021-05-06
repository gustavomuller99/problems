#include <bits/stdc++.h>
using namespace std;
int cnt = 0, m, n;
vector<pair<int,int>> c;
void check_center(int i, int j, string p[]) {
    if(i > 1 && j > 0 && j < m) {
        if(p[i-1][j] == '*' && p[i-2][j] == '*' && p[i-1][j-1] == '*' && p[i-1][j+1] == '*') {
            c.emplace_back(i-1,j);
        }
    }
}
int main() {
    cin >> n >> m;
    string p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        for (int j = 0; j < m; ++j) {
            if(p[i][j] == '*') {
                cnt++;
                check_center(i, j, p);
            }
        }
    }
    if(c.size() != 1) {cout << "NO" << endl; return 0;}
    pair<int,int> k = c[0];
    cnt--;
    for (int i = k.first-1; i >= 0 && p[i][k.second] == '*'; --i) cnt--;
    for (int i = k.first+1; i < n && p[i][k.second] == '*'; ++i) cnt--;
    for (int j = k.second-1; j >= 0 && p[k.first][j] == '*'; --j) cnt--;
    for (int j = k.second+1; j < m && p[k.first][j] == '*'; ++j) cnt--;
    if(cnt) cout << "NO" << endl;
    else cout << "YES" << endl;
}
