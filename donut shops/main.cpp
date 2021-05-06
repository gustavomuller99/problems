#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t;
    while(t--) {
        ll a,b,c;cin>>a>>b>>c;
        if(b*a<=c) cout<<b-1<<" "<<-1<<endl;
        else if(c<=a) cout<<-1<<" "<<b<<endl;
        else cout<<1<<" "<<b<<endl;
    }
}
