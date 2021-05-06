#include <bits/stdc++.h>
using namespace std;
vector<int> d;
int find(int x) {
    return (d[x] == x) ? x : d[x] = find(d[x]);
}
int main() {
    int t;
    cin >> t;

    while(t--) {
        int n; cin >> n;
        d = vector<int>(n);
        for (int i = 0; i < n; ++i) d[i] = i;
        vector<int> s(n, 1);
        for (int i = 0; i < n; ++i) {
            int p; cin >> p; p--;
            int a = find(i);
            int b = find(p);
            if(a != b) {
                s[a] += s[b];
                d[b] = a;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << s[find(i)] << " ";
        } cout << "\n";
    }
}
