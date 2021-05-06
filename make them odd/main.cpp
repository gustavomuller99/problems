#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            ll k; cin>>k; s.insert(k);
        }
        int m = 0;
        while(!s.empty()) {
            ll k = *s.rbegin();
            s.erase(k);
            if(k%2 == 0) {m++; s.insert(k/2);}
        }
        cout<<m<<endl;
    }
}
