#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin>>t; while(t--) {
        int n, d; cin>>n>>d;
        for (int i = 0; i < n; ++i) {
            ll x; cin>>x;
            if(x >= 10*d) cout << "YES\n";
            else {
                bool p = x%10==d;
                for (ll j = x-d; j >= 0; j -= d) {
                    if(j%10==0) p = true;
                }
                if(p) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
