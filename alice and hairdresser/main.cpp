#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n, m;
ull l;
ull sz[100000] = {0};
int main() {
    cin >> n >> m >> l;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        ull k;
        cin >> k;
        sz[i] = k;
        if(k > l) {
            s++;
            if(i > 0) {
                if(sz[i-1] > l) s--;
            }
        }
    }
    while(m--) {
        int op;
        cin >> op;
        if(op) {
            ull p, _l;
            cin >> p >> _l;
            p--;
            ull b = sz[p];
            sz[p] += _l;
            if(b <= l && sz[p] > l) {
                s++;
                if(p > 0) {
                    if(sz[p-1] > l) s--;
                }
                if(p < n - 1) {
                    if(sz[p+1] > l) s--;
                }
            }
        } else {
            cout << s << endl;
        }
    }
}
