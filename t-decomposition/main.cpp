#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin>>n;
    vector<pair<int, int>> t(n-1);
    vector<vector<int>> in(n+1);
    for (int i = 0; i < n-1; ++i) {
        cin>>t[i].first>>t[i].second;
        in[t[i].first].push_back(i+1); in[t[i].second].push_back(i+1);
    }
    cout << t.size() << "\n";
    for (int i = 0; i < n-1; ++i) {
        cout << 2 << " " << t[i].first << " " << t[i].second << "\n";
    }
    for (int i = 0; i < n+1; ++i) {
        if(in[i].size() >= 2) {
            for(int j = 1; j < in[i].size(); ++j) {
                cout << in[i][j] << " " << in[i][j-1] << "\n";
            }
        }
    }

}
