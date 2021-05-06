#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    if(a.size() < 3) {
        cout << max(a[0], (a.size() > 1 ? a[1] : 0));
        cout << "\n" << 1 << " ";
        if(a.size() > 1) cout << 2;
    }
    else {
        pair<int,int> d[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) d[i][j] = {INT_MAX, -1};
        d[2][0].first = max(a[1], a[2]); d[2][0].second = 0;
        d[2][1].first = max(a[0], a[2]); d[2][1].second = 1;
        d[2][2].first = max(a[0], a[1]); d[2][2].second = 2;
        for (int i = 4; i < n; i += 2) {
            for (int j = 0; j <= i-2; ++j) {
                d[i][j].first = d[i-2][j].first + max(a[i], a[i-1]);
                d[i][j].second = j;
                if(d[i-2][j].first + max(a[j], a[i-1]) < d[i][i].first) {
                    d[i][i].first = d[i-2][j].first + max(a[j], a[i-1]);
                    d[i][i].second = j;
                }
                if(d[i-2][j].first + max(a[j], a[i]) < d[i][i-1].first) {
                    d[i][i-1].first = d[i-2][j].first + max(a[j], a[i]);
                    d[i][i-1].second = j;
                }
            }
        }
        vector<pair<int, int>> p;
        int ans = INT_MAX;
        if(a.size() % 2 == 0) {
            for (int i = 0; i <= n - 2; ++i) {
                d[n-1][i].first = d[n-2][i].first + max(a[i], a[n-1]);
            }
            int s;
            for (int k = 0; k < n; ++k) {
                if(ans > d[n-1][k].first) ans = d[n-1][k].first, s = k;
            }
            p.emplace_back(s, n-1);
            for (int i = n-2; i >= 4; i -= 2) {
                if(s == i) p.emplace_back(d[i][i].second, i-1), s = d[i][i].second;
                else if(s == i-1) p.emplace_back(d[i][i-1].second, i), s = d[i][i-1].second;
                else p.emplace_back(i-1, i);
            }
            if(s == 0) p.emplace_back(1, 2);
            if(s == 1) p.emplace_back(0, 2);
            if(s == 2) p.emplace_back(0, 1);
        } else {
            int s;
            for (int k = 0; k < n; ++k) {
                if(ans > d[n-1][k].first + a[k]) ans = d[n-1][k].first + a[k], s = k;
            }
            p.emplace_back(s, -1);
            for (int i = n-1; i >= 4; i -= 2) {
                if(s == i) p.emplace_back(d[i][i].second, i-1), s = d[i][i].second;
                else if(s == i-1) p.emplace_back(d[i][i-1].second, i), s = d[i][i-1].second;
                else p.emplace_back(i-1, i);
            }
            if(s == 0) p.emplace_back(1, 2);
            if(s == 1) p.emplace_back(0, 2);
            if(s == 2) p.emplace_back(0, 1);
        }
        cout << ans << "\n";
        for (auto i = p.rbegin(); i < p.rend(); ++i) {
            cout << i->first + 1 << " ";
            if(i->second != -1) cout << i->second + 1;
            cout << "\n";
        }
    }
}
