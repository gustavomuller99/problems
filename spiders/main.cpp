#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> t;
pair<int,int> dfs(int i, int j, int f) {
    int sz=0; int v = j;
    for (int k = 0; k < t[i][j].size(); ++k) {
        if(t[i][j][k] != f) {
            auto r = dfs(i,t[i][j][k],j);
            if(r.first > sz) {
                sz = r.first;
                v = r.second;
            }
        }
    }
    return make_pair(sz+1, v);
}
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; fin>>n;
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        int k; fin>>k; t[i].resize(k);
        for (int j = 0; j < k-1; ++j) {
            int a,b; fin>>a>>b;
            t[i][a-1].push_back(b-1);
            t[i][b-1].push_back(a-1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto r = dfs(i,0,0);
        r = dfs(i, r.second, r.second);
        ans += r.first - 1;
    }
    fout<<ans<<endl;
}
