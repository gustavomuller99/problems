#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string in; cin>>in;
    int f = 0, e = 0;
    bool p = true;
    for (int i = 0; i < in.size(); ++i) f ^= in[i] == '1' ? 1 : 0;
    for (int i = in.size()-1; i >=0; --i) {
        f ^= in[i] == '1' ? 1 : 0;
        if((f != e && in[i] != '1') || (f == e && in[i] != '0')) { p = false; break; }
        e ^= in[i] == '1' ? 1 : 0;
    }
    if(p) cout << "YES";
    else cout << "NO";
}
