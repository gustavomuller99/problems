#include <bits/stdc++.h>
using namespace std;
bool is_p(int x) {
    for (int i = 2; i*i <= x; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    int n, k; cin >> n >> k;
    vector<int> p;
    for (int i = 3; i <= n; ++i) if(is_p(i)) p.push_back(i);
    int ans = 0;
    for(int u : p) {
        int l_p = 2;
        for (int i = 3; i <= u; ++i) {
            if(is_p(i)) { ans += (u == i + l_p + 1); l_p = i; }
        }
    }
    cout << (ans >= k ? "YES" : "NO") << "\n";
}
