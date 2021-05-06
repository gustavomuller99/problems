#include <bits/stdc++.h>
using namespace std;
vector<set<long long>> s(3);
vector<int> a;
vector<long long> p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < 2*n; ++i) {
        int c; cin >> c;
        s[c-1].insert(p[i%n]);
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int c; cin >> c;
        long long pr = s[c-1].empty() ? -1 : *s[c-1].begin();
        for (int j = 0; j < 3; ++j) s[j].erase(pr);
        cout << pr << " ";
    } cout << "\n";
}
