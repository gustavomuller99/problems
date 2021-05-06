#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, int>> in;
vector<vector<int>> sq;
map<ll,int> m;
void dfs(int a, int s) {
    if(in[a].second) return;
    in[a].second = 1;
    sq[s].push_back(m[in[a].first]+1);
    dfs(m[in[a].first], s);
}
int main() {
    int n; cin>>n;
    in.resize(n);
    for (int i = 0; i < n; ++i) {
        ll k; cin>>k; in[i].first = k;
        m[in[i].first] = i;
    }
    sort(in.begin(), in.end());
    int ans=0;
    for (int j = 0; j < n; ++j) {
        if(!in[j].second) {
            vector<int> nw;
            sq.push_back(nw);
            dfs(j, ans);
            ans++;
        }
    }
    cout<<ans<<endl;
    for(auto k : sq) {
        cout<<k.size()<<" ";
        for(int l : k) {
            cout<<l<<" ";
        } cout<<endl;
    }
}
