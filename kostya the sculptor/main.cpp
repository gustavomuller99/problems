#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, pair<int, int>> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<int> v(3);
    int h = 0, a = 0, k = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        cin>>v[0]>>v[1]>>v[2];
        sort(v.begin(), v.end());
        if(v[0] > h) h = v[0], k = 1, a = i;
        do {
            pair<int, int> f = {v[0], v[1]};
            if(mp.find(f) == mp.end()) mp[f] = {v[2], i};
            else {
                if(min(min(v[0], v[1]), v[2] + mp[f].first) > h) h = min(min(v[0], v[1]), v[2] + mp[f].first), k = 2, a = mp[f].second, b = i;
                if(v[2] > mp[f].first) mp[f] = {v[2], i};
            }
        } while(next_permutation(v.begin(), v.end()));
    }
    if(k==1) cout << 1 << "\n" << a+1;
    else cout << 2 << "\n" << a+1 << " " << b+1;
}
