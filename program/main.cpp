#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t--) {
        int n,m; cin>>n>>m;
        string in; cin>>in;
        vector<pair<int, pair<int,int>>> p(n+1), s(n+2);
        p[0] = {0, {0,0}};
        s[n+1] = {0, {0,0}};
        for (int i = 1; i <= n; ++i) {
            if(in[i-1] == '-') p[i].first = p[i-1].first - 1;
            else p[i].first = p[i-1].first + 1;
            p[i].second.first = max(p[i-1].second.first, p[i].first);
            p[i].second.second = min(p[i-1].second.second, p[i].first);
        }
        for (int i = n; i >= 1; --i) {
            int d = (in[i-1] == '-' ? -1 : 1);
            s[i].second.first = max(s[i+1].second.first + d, 0);
            s[i].second.second = min(s[i+1].second.second + d, 0);
        }
        for (int i = 0; i < m; ++i) {
            int l, r; cin>>l>>r;
            int mxp = p[l-1].second.first, mnp = p[l-1].second.second, cp = p[l-1].first;
            int mxs = s[r+1].second.first + cp, mns = s[r+1].second.second + cp;
            //cout << l << " " << r << "\n" << mnp << " " << mxp << " " << cp << "\n" << mns << " " << mxs << "\n";
            cout << max(mxp, mxs) - min(mnp, mns) + 1 << "\n";
        }
    }
}
