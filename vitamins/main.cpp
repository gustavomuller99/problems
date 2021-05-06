#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> d(7, 1e6), p(3);
    for (int i = 0; i < n; ++i) {
        int c; string s; cin>>c>>s;
        vector<int> l(3);
        for (int j = 0; j < s.size(); ++j) l[s[j]-'A']++, p[s[j]-'A'] = l[s[j]-'A'];
        if(l[0] && l[1] && l[2]) d[0] = min(d[0], c);
        else if(l[0] && l[1]) d[1] = min(d[1], c);
        else if(l[0] && l[2]) d[2] = min(d[2], c);
        else if(l[1] && l[2]) d[3] = min(d[3], c);
        else if(l[0]) d[4] = min(d[4], c);
        else if(l[1]) d[5] = min(d[5], c);
        else if(l[2]) d[6] = min(d[6], c);
    }
    if(!p[0] || !p[1] || !p[2]) cout << -1;
    else cout << min(d[0], min(d[1] + min(d[6], min(d[2], d[3])), min(d[2] + min(d[5], min(d[3], d[1])), min(d[3] + min(d[4], min(d[2], d[1])), d[4] + d[5] + d[6]))));
}
