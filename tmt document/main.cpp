#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, b=0, ct=0, cm=0; cin>>n;
        string s; cin>>s;
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if(s[i]=='T') ct++, b++;
            else {
                cm++;
                if(b<=0) ans = false;
                else b--;
            }
        } b=0;
        for (int i = s.size()-1; i >= 0; --i) {
            if(s[i]=='T') b++;
            else {
                if(b<=0) ans = false;
                else b--;
            }
        }
        if(ans && ct == 2*cm) cout << "YES\n";
        else cout << "NO\n";
    }
}
