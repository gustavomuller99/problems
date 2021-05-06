#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int w,h; unsigned long long n; cin>>w>>h>>n;
        unsigned long long ans = 1;
        while(w%2==0) w /= 2, ans *= 2;
        while(h%2==0) h /= 2, ans *= 2;
        if(ans >= n) cout << "YES\n";
        else cout << "NO\n";
    }
}
