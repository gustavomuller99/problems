#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<ll> in(n);
        ll s=0, x=0;
        for (int i = 0; i < n; ++i) {
            cin >> in[i];
            s += in[i];
            x ^= in[i];
        }
        cout<<"2"<<endl;
        cout<<x<<" "<<s+x<<endl;
    }
}
