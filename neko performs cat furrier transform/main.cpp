#include <bits/stdc++.h>
using namespace std;

int main() {

    int x;
    cin >> x;
    int u = 1;
    while(u <= x) {
        u <<= 1;
    }
    u -= 1;
    int op = 0;
    int _x, cnt, x_r;

    vector<int> p;
    while(u > x) {
        op++;
        if(!(op&1)) {
            x++;
        } else {
            _x = x ^ u;
            cnt = 0;
            while (_x) { _x >>= 1;cnt ++;}
            x_r = pow(2, cnt) - 1;
            x ^= x_r;
            p.push_back(cnt);
        }
    }
    cout << op << endl;
    for(auto k : p) {
        cout << k << " ";
    }
}
