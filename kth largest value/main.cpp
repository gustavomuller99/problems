#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q, a=0, b=0; cin>>n>>q;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin>>v[i], (v[i] == 1 ? a++ : b++);
    while(q--) {
        int t,x; cin>>t>>x;
        if(t==1) {
            v[x-1] = !v[x-1];
            (v[x-1] == 1 ? a++, b-- : a--, b++);
        }
        else cout << (x > a ? 0 : 1) << "\n";
    }
}
