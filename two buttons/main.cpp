#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    int ans=0;
    if(n>m) cout<<n-m;
    else {
        while(m!=n) {
            if(m%2 || m<n) m++;
            else m/=2;
            ans++;
        }
        cout<<ans<<endl;
    }

}
