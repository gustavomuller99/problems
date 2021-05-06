#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        cout<<(n==1 ? 0 : (n==2 ? m : 2*m)) << endl;
    }
}
