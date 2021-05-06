#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll n,r;cin>>n>>r;
        ll ans=0;
        if(r>=n) {
            ans += (n - 1) * n / 2;
            ans ++;
        } else {
            ans += (r + 1) * r / 2;
        }

        cout<<ans<<endl;
    }
}
