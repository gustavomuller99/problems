#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,k,m,t; cin>>n>>k>>m>>t;
    int l = n, p = k;
    for (int i = 0; i < t; ++i) {
        int o,pos; cin>>o>>pos;
        if(o) {
            if(pos<=p) p++;
            l = min(l + 1, m);
        } else {
            if(pos<p) {
                p = p - pos;
                l = l - pos;
            } else {
                l = l - (l-pos);
            }
        }
        cout << l << " " << p << "\n";
    }
}
