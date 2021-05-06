#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, d, l = -1; cin >> n >> m >> k;
    string in; cin >> in >> in;
    if(in[0] == 'h' || k == n) d = -1;
    else d = 1;
    m = (m > k ? n : 1);
    cin >> in;
    for (int i = 0; i < in.size(); ++i) {
        k += d;
        if(k == n || k == 1) d = -d;
        if(in[i] == '1') m = ((d == 1 && k != 1) || (d == -1 && k == n) ? 1 : n);
        if (m == k) { l = i + 1; break; }
    }
    if(l == -1) cout << "Stowaway";
    else cout << "Controller " << l;
}
