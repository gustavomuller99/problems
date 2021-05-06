#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin>>n>>q;
    vector<int> a, b(n), c(n);
    int m = 0, ans = 0;
    for (int i = 0; i < q; ++i) {
        int x,y; cin>>x>>y; y--;
        if(x==1) b[y]++, c[y]++, ans++, a.push_back(y);
        else if(x==2) ans -= b[y], b[y] = 0;
        else while(m <= y) { c[a[m]]--; if(b[a[m]] > c[a[m]]) ans--, b[a[m]]--; m++; }
        cout << ans << "\n";
    }
}
