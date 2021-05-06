#include <bits/stdc++.h>
using namespace std;
string f, s;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>f>>s;
    int ans = 0;
    for (int i = 0; i < f.size() - s.size() + 1; ++i) {
        bool p = true;
        char z_c = '$', o_c = '$';
        for (int j = 0; j < s.size(); ++j) {
            if(s[j]=='1' && o_c=='$') { o_c = f[i+j]; continue; }
            if(s[j]=='0' && z_c=='$') { z_c = f[i+j]; continue; }
            if(s[j]=='1' && o_c!=f[i+j]) { p = false; break; }
            if(s[j]=='0' && z_c!=f[i+j]) { p = false; break; }
        }
        if(p) { ans++; continue; }
        p = true;
        z_c = '$', o_c = '$';
        for (int j = s.size()-1; j >= 0; --j) {
            if(s[j]=='1' && o_c=='$') { o_c = f[i+(s.size()-j-1)]; continue; }
            if(s[j]=='0' && z_c=='$') { z_c = f[i+(s.size()-j-1)]; continue; }
            if(s[j]=='1' && o_c!=f[i+(s.size()-j-1)]) { p = false; break; }
            if(s[j]=='0' && z_c!=f[i+(s.size()-j-1)]) { p = false; break; }
        }
        if(p) ans++;
    }
    cout << ans << "\n";
}
