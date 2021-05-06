#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll l,r; cin>>l>>r;
        (2*l <= r) ? cout<<l<<" "<<2*l<<endl : cout<<"-1 -1"<<endl;
    }
}
