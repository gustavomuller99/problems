#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; bool p = true;
    vector<int> a(6);
    for (int i = 0; i < 6; ++i) cin>>a[i];
    cin>>n;
    vector<string> b = {"S", "M", "L", "XL", "XXL", "XXXL"};
    vector<vector<int>> sh(6);
    vector<string> ans(n, "#");
    for (int i = 0; i < n; ++i) {
        string s; cin>>s;
        vector<string> in;
        int br = 0, sz = 0;
        for (int j = 0; j < s.size(); ++j) {
            sz++;
            if(s[j] == ',') in.push_back(s.substr(br, sz-1)), br = j+1, sz = 0;
        }
        in.push_back(s.substr(br, sz));
        if(in.size() == 1) {
            for (int j = 0; j < 6; ++j) {
                if(in[0] == b[j]) a[j]--, ans[i] = b[j];
                if(a[j] < 0) p = false;
            }
        } else for (int j = 0; j < 6; ++j) {
            if(in[0] == b[j]) sh[j].push_back(i);
            if(in[1] == b[j]) sh[j].push_back(i);
        }
    }
    for (int i = 0; i < 6; ++i) {
        if(i > 0) {
            for (int j = 0; j < sh[i-1].size(); ++j) {
                if(ans[sh[i-1][j]] == "#") {
                    ans[sh[i-1][j]] = b[i];
                    a[i]--;
                    if(a[i] < 0) p = false;
                }
            }
        }
        for (int j = 0; j < sh[i].size(); ++j) {
            if(ans[sh[i][j]] == "#") {
                if(i < 5 && a[i] == 0) break;
                ans[sh[i][j]] = b[i];
                a[i]--;
                if(i == 5 && a[i] < 0) p = false;
            }
        }
    }
    if(!p) cout << "NO";
    else {
        cout << "YES\n";
        for(const string& k : ans) cout << k << "\n";
    }
}
