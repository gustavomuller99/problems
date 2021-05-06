#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;cin>>t; while(t--) {
        ll m,l,r; cin>>l>>r>>m;
        for (ll i = l; i <= r; ++i) {
            ll d = m/i;
            if(m-i*d <= r-l && d) {
                cout << i << " " << r << " " << r-(m-i*d) << "\n"; break;
            } else if(i*(d+1)-m <= r-l) {
                cout << i << " " << r-(i*(d+1)-m) << " " << r << "\n"; break;
            }
        }
    }
}
