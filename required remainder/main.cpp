#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll x,y,n; cin>>x>>y>>n;
        cout<<(n-n%x+y <= n ? n-n%x+y : n-n%x-(x-y))<<endl;
    }
}
