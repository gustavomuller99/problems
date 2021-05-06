#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<pair<int, ll>> w(10e5);
int find_set(int v) {
    if (v == w[v].first) return v;
    return w[v].first = find_set(w[v].first);
}
void union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        if(w[a].second > w[b].second) swap(a, b);
        w[b].first = a;
    }
}
int main() {
    int n,k,m; cin>>n>>k>>m;
    map<string, int> h;
    ll c=0;
    for (int i=0;i<n;++i) {
        string s; cin>>s; h.insert(make_pair(s, i));
        w[i].first = i;
    }
    for (int j=0;j<n;++j) {
        ll s; cin>>s;
        w[j].second=s;
    }
    for (int l=0;l<k;++l) {
        int x; cin>>x;
        int u; cin>>u;
        for (int i=1;i<x;++i) {
            int v; cin>>v;
            union_sets(u-1,v-1);
            u = v;
        }
    }
    for (int i=0;i<m;++i) {
        string s; cin>>s;
        int x = h[s];
        c += w[find_set(x)].second;
    }
    cout<<c<<endl;
}
