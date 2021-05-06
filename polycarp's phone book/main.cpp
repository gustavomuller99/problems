#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        set<string> r;
        for (int j = 0; j < 9; ++j) {
            for (int k = 1; k <= 9-j; ++k) {
                string b = a[i].substr(j, k);
                if(!r.count(b)) mp[b]++;
                r.insert(b);
            }
        }
    }
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        pair<int,int> add; int l = INT_MAX;
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k <= 9-j; ++k) {
                string b = a[i].substr(j, k);
                if(mp[b]==1 && l > k) add = {j, k}, l = k;
            }
        }
        ans[i] = a[i].substr(add.first, add.second);
    }
    for(string x : ans) cout << x << "\n";
}
