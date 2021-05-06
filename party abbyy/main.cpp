#include <bits/stdc++.h>
using namespace std;
vector<int> dsu(10e5+1);
vector<int> s(10e5+1, 1);
int find(int a) {
    if(dsu[a] == 0 || dsu[a] == -1) return a;
    else return dsu[a] = find(dsu[a]);
}
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if(s[a] < s[b]) swap(a, b);
    s[a] += s[b];
    dsu[b] = a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        if(find(a) != find(b)) join(a,b);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a == b) dsu[a] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = find(i);
        if(dsu[p] != -1) ans = max(ans, s[p]);
    }
    cout << ans << endl;
}
