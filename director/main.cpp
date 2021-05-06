#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<vector<pair<string, bool>>> nm(26), sn(26);
    vector<vector<string>> ans(26);
    vector<int> cnt(26), mt(26);
    for (int i = 0; i < n; ++i) {
        string s; cin>>s;
        nm[s[0] - 'A'].push_back({s, false});
    }
    for (int i = 0; i < n; ++i) {
        string s; cin>>s;
        sn[s[0] - 'A'].push_back({s, false});
    }
    for (int i = 0; i < 26; ++i) {
        sort(nm[i].begin(), nm[i].end());
        sort(sn[i].begin(), sn[i].end());
        cnt[i] = min(nm[i].size(), sn[i].size());
        if(nm[i].size() >= sn[i].size()) mt[i] = nm[i].size() - sn[i].size();
        else mt[i] = 0;
    }
    for (int i = 0; i < 26; ++i) {
        int am = 0;
        for (int j = 0; j < nm[i].size(); ++j) {
            bool f = false;
            for (int k = 0; k < 26; ++k) {
                if(i != k && (cnt[k] == sn[k].size() || am == mt[i])) continue;
                for (int l = 0; l < sn[k].size(); ++l) {
                    if(sn[k][l].second) continue;
                    ans[i].push_back(nm[i][j].first + " " + sn[k][l].first);
                    sn[k][l].second = true;
                    f = true;
                    break;
                }
                if(f) {
                    if(i != k) am++, cnt[k]++;
                    break;
                }
            }
        }
    }
    vector<string> p;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            p.push_back(ans[i][j]);
        }
    }
    for (int i = 0; i < p.size() - 1; ++i) {
        cout << p[i] << ", ";
    }
    cout << p[p.size() - 1];
}
