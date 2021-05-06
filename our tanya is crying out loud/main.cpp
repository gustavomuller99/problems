#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n,k,a,b; cin>>n>>k>>a>>b;
    ll ans = 0;
    if(k==1) {cout<<(n-1)*a<<endl; return 0;}
    while(n>1) {
        if(n%k) {
            ans+=(n%k)*a;
            n-=n%k;
        } else {
            if(b < a*(n-n/k)) ans+=b;
            else ans+=a*(n-n/k);
            n/=k;
        }
    }
    if(!n) ans-=a;
    cout<<ans<<endl;
}
