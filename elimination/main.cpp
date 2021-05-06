#include <bits/stdc++.h>
using namespace std;

int main() {
    int c,d,n,m,k; cin>>c>>d>>n>>m>>k;
    int p = n*m-k;
    int ans=0;
    if(p>0) {
        ans = min((p / n) * c, p * d);
        if(ans==(p/n)*c)ans += (p % n) ? min(c, (p % n) * d) : 0;
    }
    cout<<ans<<endl;
}
