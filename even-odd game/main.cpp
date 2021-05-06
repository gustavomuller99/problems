#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        int n, ie = 0, io = 0; cin>>n;
        ll a = 0, b = 0;
        vector<ll> e, o;
        for (int i = 0; i < n; ++i) {
            ll x; cin>>x;
            if(x%2) o.push_back(x);
            else e.push_back(x);
        }
        sort(e.begin(), e.end(), greater<>());
        sort(o.begin(), o.end(), greater<>());
        for (int i = 0; i < n; ++i) {
            if(i%2==0) {
                if(io == o.size()) a += e[ie], ie++;
                else if(ie < e.size() && e[ie] >= o[io]) {
                    a += e[ie];
                    ie++;
                } else io++;
            } else {
                if(ie == e.size()) b += o[io], io++;
                else if(io < o.size() && o[io] >= e[ie]) {
                    b += o[io];
                    io++;
                } else ie++;
            }
        }
        if(a > b) cout << "Alice\n";
        else if(b > a) cout << "Bob\n";
        else cout << "Tie\n";
    }
}
