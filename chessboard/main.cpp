#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<string>> c(4);
    vector<pair<int,int>> p(4);
    vector<string> a(2);
    for (int i = 0; i < 2; ++i) a[i].resize(n);
    for (int i = 0; i < n; ++i) {
        a[0][i] = (i % 2) ? '0' : '1';
        a[1][i] = (i % 2) ? '1' : '0';
    }
    for (int i = 0; i < 4; ++i) {
        c[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if(l == 0 && c[i][j][k] != a[0][k]) (j % 2) ? p[i].first++ : p[i].second++;
                    else if(l == 1 && c[i][j][k] != a[1][k]) (j % 2) ? p[i].second++ : p[i].first++;
                }
            }
        }
    }
    int ans = INT_MAX;
    vector<int> pm(4);
    for (int i = 0; i < 4; ++i) pm[i] = i;
    do {
        ans = min(ans, p[pm[0]].first + p[pm[1]].second + p[pm[2]].second + p[pm[3]].first);
        ans = min(ans, p[pm[0]].second + p[pm[1]].first + p[pm[2]].first + p[pm[3]].second);
    } while(next_permutation(pm.begin(), pm.end()));
    cout << ans << "\n";
}
