#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main() {
    int l, r; cin>>l>>r;
    vector<ull> d, t;
    for (int i=0;i<=30;++i) {
        ull k = pow(2, i);
        if(k>r) break;
        d.push_back(k);
    }
    for (int j=0;j<=23;++j) {
        ull k = pow(3, j);
        if(k>r) break;
        t.push_back(k);
    } int ans = 0;
    for (ull i : d) {
        for (ull j : t) {
            if(i*j>=l&&i*j<=r) ans++;
        }
    }
    cout<<ans<<endl;
}
