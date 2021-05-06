#include <bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> s;
int g(int a) {
    if(d[a] == -1) return a;
    return d[a] = (a == d[a] ? a : g(d[a]));
}
void j(int a, int b) {
    a = g(a); b = g(b);
    s[a] += s[b];
    d[b] = a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    d.resize(n, -1);
    s.resize(n);
    cout << 1 << " ";
    for (int i = 0; i < n; ++i) {
        int p; cin >> p; p--;
        d[p] = p;
        s[p] = 1;
        if(p > 0 && d[p-1] != -1) j(p, p-1);
        if(p < n-1 && d[p+1] != -1) j(p, p+1);
        cout << i+2-s[g(n-1)] << " ";
    }
}