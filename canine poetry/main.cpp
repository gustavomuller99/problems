#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin>>s;
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i-1] == s[i] || (i > 1 && s[i-2] == s[i])) {
                s[i] = '$';
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
