#include <bits/stdc++.h>
using namespace std;
int n,k;
map<char, vector<int>> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>k>>n;
    string s; cin>>s;
    for (char i = 'a'; i <= 'z'; ++i) mp[i] = vector<int> ();
    for (int i = 0; i < s.size(); ++i) mp[s[i]].push_back(i);
    vector<unsigned long long> ans;
    for (int i = 0; i < k; ++i) {
        string p; cin>>p; unsigned long long add = 0;
        for (int j = 0; j < p.size(); j++) {
            if(j<s.size() && s[j]==p[j]) continue;
            if(mp[p[j]].empty()) { add += p.size(); continue; }
            int l = 0, r = mp[p[j]].size();
            while(r > l + 1) {
                int mid = (l + r) / 2;
                if(mp[p[j]][mid] <= j) l = mid;
                else r = mid;
            }
            add += min(abs(j-mp[p[j]][l]), r != mp[p[j]].size() ? abs(j-mp[p[j]][r]) : INT_MAX);
        }
        ans.push_back(add);
    }
    for(unsigned long long x : ans) cout << x << "\n";
}
