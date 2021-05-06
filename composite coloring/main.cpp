#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        map<int, int> mp;
        int n, m = 0; cin >> n;
        vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        vector<int> c;
        for (int i = 0; i < n; ++i) {
            int k, d = 1; cin >> k;
            for (int j = 0; j < pr.size(); ++j) {
                if(k % pr[j] == 0) {d = pr[j]; break;}
            }
            if(mp.find(d) == mp.end()) {
                mp.insert({d, m});
                m++;
            }
            c.push_back(mp[d]+1);
        }
        cout << m << "\n";
        for(int k : c) cout << k << " ";
        cout << "\n";
    }
}
