#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        ll n; cin>>n;
        while(n % 2 == 0) n /= 2;
        if(n%2 && n != 1) cout << "YES\n";
        else cout << "NO\n";

    }
}
