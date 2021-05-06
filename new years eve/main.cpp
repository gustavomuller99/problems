#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ll n,k; cin>>n>>k;
    ll p = 1;
    while(p<=n) {p = p*2;}
    cout<<(k==1 ? n : p-1)<<endl;
}
