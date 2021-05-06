#include <bits/stdc++.h>
using namespace std;
int d[26][26] = {0};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    for (int i = 0; i < n; ++i) {
        string in; cin>>in;
        int s = in.size();
        int l = in[0]-97;
        int r = in[in.size()-1]-97;
        for (int j = 0; j < 26; ++j) {
            if(d[j][l] != 0) d[j][r] = max(d[j][r], d[j][l] + s);
        }
        d[l][r] = max(d[l][r], s);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans = max(ans, d[i][i]);
    }
    cout<<ans<<endl;
}
