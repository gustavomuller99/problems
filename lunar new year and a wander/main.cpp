#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int main() {
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> visited(n+1);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<>> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int x = q.top();
        cout << x << " ";
        q.pop();
        for(int k : g[x]) {
            if(!visited[k]) {
                q.push(k);
                visited[k] = 1;
            }
        }
    }
}
