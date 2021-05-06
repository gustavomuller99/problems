#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,m,k; cin>>n>>m>>k;
    pair<ll, pair<int,int>> d[n][m][101];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l <= 100; ++l) {
                d[i][j][l] = {0, {-1, -1}};
            }
        }
    }
    vector<pair<pair<int,int>, pair<ll,ll>>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].second.first >> a[i].second.second >> a[i].first.first;
        a[i].first.second = i+1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < m; ++j) {
            for (int o = 0; o <= a[j].second.second - a[j].second.first; ++o) {
                if(i == 0) { d[i][j][o] = {a[j].second.first + o, {-1,-1}}; continue; }
                for (int l = 0; l < j; ++l) {
                    if(a[j].first.first == a[l].first.first) continue;
                    ll v = a[j].second.first + o;
                    if(v - k >= a[l].second.first && v - k <= a[l].second.second && d[i-1][l][v - k - a[l].second.first].first != 0
                       && d[i-1][l][v - k - a[l].second.first].first + v > d[i][j][o].first)
                        d[i][j][o] = {d[i-1][l][v - k - a[l].second.first].first + v, {l, v - k - a[l].second.first}};
                    if(v % k == 0 && v / k >= a[l].second.first && v / k <= a[l].second.second && d[i-1][l][v / k - a[l].second.first].first != 0
                       && d[i-1][l][v / k - a[l].second.first].first + v > d[i][j][o].first)
                        d[i][j][o] = {d[i-1][l][v / k - a[l].second.first].first + v, {l, v / k - a[l].second.first}};
                }
            }
        }
    }
    ll mx = 0; int c = -1,o;
    for (int i = n-1; i < m; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if(d[n-1][i][j].first != 0 && d[n-1][i][j].first > mx) mx = d[n-1][i][j].first, c = i, o = j;
        }
    }
    if(c == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<pair<int, ll>> ans;
        for (int i = n-1; i >= 0; --i) {
            ans.emplace_back(a[c].first.second, a[c].second.first + o);
            int cp = c;
            c = d[i][c][o].second.first;
            o = d[i][cp][o].second.second;
        }
        for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
            cout << i->first << " " << i->second << "\n";
        }
    }
}
