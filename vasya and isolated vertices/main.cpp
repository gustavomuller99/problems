#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m;
    cin>>n>>m;
    cout<<(n - 2*m > 0 ? n-2*m : 0)<<" ";
    ll v = 0;
    while(m>0) {
        v++; m-=v-1;
    }
    cout<<n-v<<endl;



}
