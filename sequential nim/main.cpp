#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, k, i, f=0; cin>>n;
        for (i = 1; i <= n; ++i) {
            cin>>k;
            if(k>1 && !f) f = i;
        }
        if(f) cout << (f % 2 ? "First" : "Second") << endl;
        else cout << (n % 2 ? "First" : "Second") << endl;
    }

}
