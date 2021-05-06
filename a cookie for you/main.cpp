#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main() {
    int t; cin>>t;
    while(t--) {
        ull v,c,n,m; cin>>v>>c>>n>>m;
        if(v+c<n+m) cout<<"NO"<<endl;
        else if(v>=c&&m<=c||v<=c&&m<=v) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
