#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        ll n,k; cin>>n>>k;
        if(n <= k) cout << k/n + (k%n ? 1 : 0) << "\n";
        else {
            cout << (n % k ? 2 : 1) << "\n";
        }
    }

}
