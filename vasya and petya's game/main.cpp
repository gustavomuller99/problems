#include <bits/stdc++.h>
using namespace std;
bool p(int x) {
    for(int i = 2; i*i <= x; ++i) if(x%i==0) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false); cout.tie(nullptr);
    int n; cin >> n;
    set<int> ans;
    for (int i = 2; i <= n; ++i) {
        if(p(i)) for (int j = i; j <= n; j*=i) ans.insert(j);
    }
    cout << ans.size() << "\n";
    for(int k : ans) cout << k << " ";
}
