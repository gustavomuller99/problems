#include <bits/stdc++.h>
using namespace std;
vector<int> ds;
int f(int x) {
    if(!ds[x]) return x;
    return ds[x] = f(ds[x]);
}
int main() {
    int n, m; cin>>n>>m;
    ds.resize(n+1);
    if(m != n-1) cout<<"no"<<endl;
    else {
        for (int i = 0; i < m; ++i) {
            int u, v; cin>>u>>v;
            if(f(u) == f(v)) {
                cout<<"no"<<endl; return 0;
            }
            ds[f(u)] = f(v);
        }
        cout<<"yes"<<endl;
    }
}
