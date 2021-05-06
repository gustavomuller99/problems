#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n; cin>>m>>n;
    vector<vector<int>> g(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int k; cin>>k; g[i].push_back(k);
        }
    }
    for (int i = 1; i < n; ++i) {
        g[0][i] += g[0][i-1];
    }
    for (int i = 1; i < m; ++i) {
        g[i][0] += g[i-1][0];
        for (int j = 1; j < n; ++j) {
            g[i][j] += (g[i][j-1] > g[i-1][j]) ? g[i][j-1] : g[i-1][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        cout<<g[i][n-1]<<" ";
    } cout<<endl;
}
