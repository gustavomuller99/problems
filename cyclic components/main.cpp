#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> g;
int dfs(int j) {
    stack<int> s;
    s.push(j);
    while(!s.empty()) {

    }
    return 0;
}
int main() {
    cin>>n>>m;
    v.resize(n+1);
    g.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int c = 0;
    for(auto x : g) {
        for(auto y : x) {
            cout<<y<<" ";
        }cout << endl;
    }
    for (int j = 1; j <= n; ++j) {

    }
    cout << endl;
    cout << c << endl;
}
