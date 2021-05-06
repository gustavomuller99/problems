#include <bits/stdc++.h>
using namespace std;
int ice[1000][1000] = {0};
int w = 0, h = 0;

void dfs(int i, int j) {
    for (int k=0;k<w;++k) {
        int a = ice[i][k];
        ice[i][k] = 2;
        if(a==1) dfs(i, k);
    }
    for (int k=0;k<h;++k) {
        int a = ice[k][j];
        ice[k][j] = 2;
        if(a==1) dfs(k, j);
    }
}

int main() {
    int n; cin>>n;
    vector<pair<int, int>> d;
    while(n--) {
        int i, j; cin>>i>>j;
        d.emplace_back(i-1, j-1);
        ice[i-1][j-1] = 1;
        w = (j > w) ? j : w;
        h = (i > h) ? i : h;
    }
    int cc = 0;
    for (auto k : d) {
        if(ice[k.first][k.second]==1) {ice[k.first][k.second] = 2; cc++; dfs(k.first, k.second);}
    }
    cout<<cc-1<<endl;
}
