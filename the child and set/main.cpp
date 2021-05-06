#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main() {
    int s, l; cin >> s >> l;
    for (int i = l; i >= 1; --i) {
        if(s - (i & -i) >= 0) s -= i & -i, ans.push_back(i);
    }
    if(s > 0) cout << -1;
    else {
        cout << ans.size() << "\n";
        for(int k : ans) cout << k << " ";
    }
}
