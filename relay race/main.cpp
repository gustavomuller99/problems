#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> m;
vector<vector<vector<int>>> d;
int n;
int f(int i, int j, int k) {
    if(d[i][j][k] != INT_MIN) return d[i][j][k];
    int l = i + j - k;
    int c;
    if(i == k && l == j) c = m[i][j];
    else c = m[i][j] + m[k][l];
    int d1 = (i < n-1 && k < n-1 ? f(i+1, j, k+1) : INT_MIN);
    int d2 = (i < n-1 && l < n-1 ? f(i+1, j, k) : INT_MIN);
    int d3 = (j < n-1 && l < n-1 ? f(i, j+1, k) : INT_MIN);
    int d4 = (j < n-1 && k < n-1 ? f(i, j+1, k+1) : INT_MIN);
    if(d1 == INT_MIN && d2 == INT_MIN && d3 == INT_MIN && d4 == INT_MIN) d[i][j][k] = c;
    else d[i][j][k] = c + max(d1, max(d2, max(d3, d4)));
    return d[i][j][k];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    m.resize(n, vector<int> (n)), d.resize(n, vector<vector<int>> (n, vector<int> (n, INT_MIN)));
    vector<vector<pair<int,int>>> dir(n, vector<pair<int,int>> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin>>m[i][j];
    cout << f(0,0,0);
}
