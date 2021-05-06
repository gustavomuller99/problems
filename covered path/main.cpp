#include <bits/stdc++.h>
using namespace std;

int main() {
    int v1,v2,t,d,ans=0; cin>>v1>>v2>>t>>d;
    if(v1 < v2) swap(v1,v2);
    while(t--) {
        if(v1 <= v2) ans += v1, v1 += d;
        else ans += v2, v2 += d;
    }
    cout << ans;
}
