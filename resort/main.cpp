#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> d;
vector<int> t;
int main() {
    int n; cin>>n;
    p.resize(n+1);
    d.resize(n+1);
    t.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        p[i] = k;
        d[k]++;
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if(t[i] == 1) {
            vector<int> path;
            int k = i;
            while (true) {
                if (d[k] > 1) break;
                path.push_back(k);
                if (p[k] == 0) break;
                k = p[k];
            }
            if(path.size() > ans.size()) ans = path;
        }
    }
    cout << ans.size() << endl;
    for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
        cout << *i << " ";
    } cout << endl;

}
