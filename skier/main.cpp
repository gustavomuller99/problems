#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    map<char, pair<int,int>> d = {
            {'N', {0,1}},
            {'S', {0, -1}},
            {'W', {-1, 0}},
            {'E', {1, 0}}
    };
    while(t--) {
        set<pair<pair<int,int>, pair<int,int>>> seg;
        pair<int,int> p = {0,0};
        string in; cin>>in;
        int ans = 0;
        for (int i = 0; i < in.size(); ++i) {
            ans += (seg.count(make_pair(p, make_pair(p.first + d[in[i]].first, p.second + d[in[i]].second))) || seg.count(make_pair(make_pair(p.first + d[in[i]].first, p.second + d[in[i]].second), p))) ? 1 : 5;
            seg.insert(make_pair(p, make_pair(p.first + d[in[i]].first, p.second + d[in[i]].second)));
            p.first += d[in[i]].first;
            p.second += d[in[i]].second;
        }
        cout << ans << endl;
    }
}
