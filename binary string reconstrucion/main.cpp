#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n0, n1, n2; cin>>n0>>n1>>n2;
        string ans;
        for (int i = 0; i < n2; ++i) {
            if(ans.length() == 0) ans += "11";
            else ans += '1';
        }
        if(n1 && ans.length()) {
            ans += '0';
            n1--;
        }
        for (int i = 0; i < n0; ++i) {
            if(ans.length() == 0) ans += "00";
            else ans += '0';
        }
        for (int i = 0; i < n1; ++i) {
            if(ans.length() == 0) ans += "01";
            else ans += (ans[ans.length()-1] == '1' ? '0' : '1');
        }
        cout << ans << endl;
    }
}
