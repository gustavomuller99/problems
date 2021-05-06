#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> c(n),pl(n),pr(n),v(n, 1);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        cin>>c[i]; pl[i] = i-1; pr[i] = i+1;
        pos[c[i]].push_back(i);
    }
    int ans = 0;
    for (int i = n-1; i >= 0; ++i) {
        if(!v[i]) continue;
        for(auto it = pos[c[i]].rbegin(); it < pos[c[i]].rend(); ++it) {
            v[*it] = false;

        }

    }

}
