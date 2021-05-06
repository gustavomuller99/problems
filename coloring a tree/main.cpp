#include <bits/stdc++.h>
using namespace std;
vector<pair<int, vector<int>>> t(10000);
int mv = 0;
void dfs(int v, int c) {
    if(c != t[v].first) mv++;
    for(int k : t[v].second) dfs(k, t[v].first);
}

int main() {
    int n; cin>>n;
    for (int i=1;i<n;++i) {
        int k; cin>>k;
        t[k-1].second.push_back(i);
    }
    for (int j=0;j<n;++j) {
        int k; cin>>k;
        t[j].first = k;
    }
    dfs(0, 0);
    cout<<mv<<endl;
}
