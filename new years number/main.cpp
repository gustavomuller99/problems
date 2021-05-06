#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        bool ans = false;
        for (int i = 0; i <= n/2020; ++i) {
            int k = n - 2020*i;
            if(k % 2021 == 0) ans = true;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
