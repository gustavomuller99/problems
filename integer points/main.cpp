#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll a;
        int e=0, o=0;
        for (int i=0;i<n;++i) {
            cin>>a;
            (a % 2) ? o++ : e++;
        }
        int m; cin>>m;
        ll b; ll ans=0;
        for (int j=0;j<m;++j) {
            cin>>b;
            (b % 2 ? ans+=o : ans+=e);
        }
        cout<<ans<<endl;

    }
}
