#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main() {
    int t; cin>>t; while(t--) {
        ll n, k; cin>>n>>k;
        if(n%2==0) cout << (k%n==0 ? n : k%n) << "\n";
        else {
            ll ans = (k + (k-1)/(n/2))%n;
            cout << (ans == 0 ? n : ans) << "\n";
        }
    }
}
