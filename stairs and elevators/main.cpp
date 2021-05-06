#include <bits/stdc++.h>
using namespace std;
int n, m, s, e, v;
vector<int> ps, pe;
int c(int x1, int y1, int y2, int x3, int y3, int step) {
    int r = abs(y1-y2) + abs(y2-y3);
    r += abs(x1-x3)/step + (abs(x1-x3)%step ? 1 : 0);
    return r;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>s>>e>>v;
    ps.resize(s), pe.resize(e);
    for (int i = 0; i < s; ++i) cin >> ps[i];
    for (int i = 0; i < e; ++i) cin >> pe[i];
    sort(ps.begin(), ps.end()); sort(pe.begin(), pe.end());
    int q; cin>>q;
    while(q--) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        if(x1 == x2) cout<<abs(y1 - y2)<<"\n";
        else {
            int ans = INT_MAX;
            vector<int> p = {y1, y2, y1, y2};
            if(e) for (int i = 0; i < 2; ++i) {
                int l = 0, r = pe.size();
                while(r > l + 1) {
                    int mid = (l + r) / 2;
                    if(pe[mid] > p[i]) r = mid;
                    else l = mid;
                }
                ans = min(ans, c(x1, y1, pe[l], x2, y2, v));
                if(l != pe.size()-1) ans = min(ans, c(x1, y1, pe[l+1], x2, y2, v));
            }
            if(s) for (int i = 2; i < 4; ++i) {
                int l = 0, r = ps.size();
                while(r > l + 1) {
                    int mid = (l + r) / 2;
                    if(ps[mid] > p[i]) r = mid;
                    else l = mid;
                }
                ans = min(ans, c(x1, y1, ps[l], x2, y2, 1));
                if(l != ps.size()-1) ans = min(ans, c(x1, y1, ps[l+1], x2, y2, 1));
            }
            cout << ans << "\n";
        }
    }
}
