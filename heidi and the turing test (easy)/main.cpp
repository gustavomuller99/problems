#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<pair<int,int>> c;
    for (int i = 0; i < 4*n+1; ++i) {
        int x1,y1; cin>>x1>>y1;
        c.emplace_back(x1, y1);
    }
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c.size(); ++j) {
            for (int l = 0; l < c.size(); ++l) {
                for (int m = 0; m < c.size(); ++m) {
                    int xl = min(c[i].first, min(c[j].first, min(c[l].first, c[m].first))), xr = max(c[i].first, max(c[j].first, max(c[l].first, c[m].first)));
                    int yl = min(c[i].second, min(c[j].second, min(c[l].second, c[m].second))), yr = max(c[i].second, max(c[j].second, max(c[l].second, c[m].second)));
                    int ans = -1, cnt = 0;
                    for (int k = 0; k < c.size(); ++k) {
                        if(k == i || k == j) continue;
                        if(c[k].first == xl && (c[k].second < yl || c[k].second > yr)) cnt++, ans = k;
                        else if(c[k].first == xr && (c[k].second < yl || c[k].second > yr)) cnt++, ans = k;
                        else if(c[k].second == yl && (c[k].first < xl || c[k].first > xr)) cnt++, ans = k;
                        else if(c[k].second == yr && (c[k].first < xl || c[k].first > xr)) cnt++, ans = k;
                        else if(c[k].first != xl && c[k].first != xr && c[k].second != yl && c[k].second != yr) cnt++, ans = k;
                    }
                    if(cnt == 1) { cout << c[ans].first << " " << c[ans].second << "\n"; return 0; }
                }
            }
        }
    }

}
