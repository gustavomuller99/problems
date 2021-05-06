#include <bits/stdc++.h>
using namespace std;
int a, b, c;
bool f(int x) {
    int a_c = a, b_c = b, c_c = c;
    if(a_c > x && c_c > x) return false;
    else {
        if(a_c < x) {
            int a_c_c = a_c;
            a_c += min(x - a_c_c, b_c);
            b_c -= min(x - a_c_c, b_c);
        }
        if(c_c < x) {
            int c_c_c = c_c;
            c_c += min(x - c_c_c, b_c);
            b_c -= min(x - c_c_c, b_c);
        }
        if(a_c > x && b_c < x) {
            int b_c_c = b_c;
            b_c += min(a_c - x, x - b_c_c);
            a_c -= min(a_c - x, x - b_c_c);
        }
        if(c_c > x && b_c < x) {
            int b_c_c = b_c;
            b_c += min(c_c - x, x - b_c_c);
            c_c -= min(c_c - x, x - b_c_c);
        }
        return a_c <= x && b_c <= x && c_c <= x;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int l = 0, r = 1;
        while (!f(r)) r *= 2;
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if (f(mid)) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
}

