#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        int a=-1,b=(int)r.size(),c_a=0,c_b=0,s_a=0,s_b=0,m=0;
        while(a < b - 1) {
            if(c_a <= c_b) {
                a++;
                c_a += r[a]; s_a += r[a];
                if(c_a > c_b) { c_b = 0; m++; }
            } else {
                b--;
                c_b += r[b]; s_b += r[b];
                if(c_b >= c_a) {
                    if(c_b == c_a && a < b - 1) { b--; c_b += r[b]; s_b += r[b]; }
                    c_a = 0;
                    m++;
                }
            }
        }
        if(c_a != 0 && c_b != 0) m++;
        cout << m << " " << s_a << " " << s_b << " " << endl;
    }
}
