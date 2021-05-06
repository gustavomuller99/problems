#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll x; cin>>x;
        (x%2) ? cout<<x-1<<" "<<1<<endl : cout<<x/2<<" "<<x/2<<endl;
    }
}
