#include <bits/stdc++.h>
using namespace std;
vector<int> p(26, -1);
int find(int x) {
    return (p[x] == x) ? x : p[x] = find(p[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string c; cin >> c;
        if(p[c[0] - 'a'] == -1) p[c[0] - 'a'] = c[0] - 'a';
        for (int j = 1; j < c.size(); ++j) {
            if(p[c[j] - 'a'] == -1) p[c[j] - 'a'] = c[j] - 'a';
            int a = find(c[j] - 'a');
            int b = find(c[j-1] - 'a');
            if(a != b) {
                p[a] = b;
            }
        }
    }
    set<int> ans;
    for (int i = 0; i < 26; ++i) {
        if(p[i] != -1) ans.insert(find(i));
    }
    cout << ans.size() << "\n";
}
