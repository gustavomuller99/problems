#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll p,a,b,c; cin>>p>>a>>b>>c;
        cout << min(((p-1)/b)*b + b - p, min(((p-1)/a)*a + a - p, ((p-1)/c)*c + c - p)) << "\n";
    }
}
