#include <bits/stdc++.h>
using namespace std;
bool p(unsigned long long x) {
    for (int i = 2; i*i <= x; ++i) {
        if(x%i==0) return false;
    }
    return true;
}
int main() {
    int t; cin>>t; while(t--) {
        unsigned long long d,l,r; cin>>d;
        for (unsigned long long i = d+1;; ++i) {
            if(p(i)) { l = i; break; }
        }
        for (unsigned long long i = l+d;; ++i) {
            if(p(i)) { r = i; break; }
        }
        cout << l*r << "\n";
    }
}
