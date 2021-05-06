#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll b, a;
        for (int i=1;i<=n;++i) {
            cin>>a;
            if(i%2) b = (a>0 ? a : -a);
            else b = (a<0? a : -a);
            cout<<b<<" ";
        } cout<<endl;
    }
}
