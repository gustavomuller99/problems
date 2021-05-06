#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll n; cin>>n;
        ll mx=1;
        for (int i=2;i*i<=n;++i)
            if(n%i==0) {mx=n/i; break;}
        cout<<mx<<" "<<n-mx<<endl;
    }
}
