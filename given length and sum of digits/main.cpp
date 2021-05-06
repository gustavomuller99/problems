#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,s; cin>>m>>s;
    if((s == 0 && m > 1) || s > 9*m) cout << "-1 -1";
    else {
        char a[m], b[m];
        for (int i = 0; i < m; ++i) a[i] = 9;
        b[0] = 1; for (int i = 1; i < m; ++i) b[i] = 0;
        int sa = m*9, sb = 1;
        for (int i = m-1; i >= 0; --i) {
            int d = sa - s;
            if(d == 0) break;
            if(d > 9) a[i] = 0, sa = sa - 9;
            else a[i] = 9 - d, sa = sa - d;
        }
        for (int i = m-1; i >= 0; --i) {
            int d = s - sb;
            if(d == 0) break;
            if(d >= 9) sb = sb + (9 - b[i]), b[i] = 9;
            else sb = sb + d, b[i] = d + b[i];
        }
        for (int j = 0; j < m; ++j) {
            cout << (char) (b[j] + '0');
        }
        cout << " ";
        for (int j = 0; j < m; ++j) {
            cout << (char) (a[j] + '0');
        }
    }
}
