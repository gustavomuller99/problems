#include <bits/stdc++.h>
using namespace std;
struct nd {int t, z, y;};
int m, n;
vector<nd> a;
bool f(int t) {
    int s = 0;
    for(auto k : a) {
        int c = t;
        while(c >= 0) {
            s += min(c/k.t, k.z);
            c -= min(c, k.t * k.z);
            c -= k.y;
        }
    }
    return s >= m;
}
int main() {
    cin >> m >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].t >> a[i].z >> a[i].y;
    int l = 0, r = 1;
    while(!f(r)) r *= 2;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    if(!m) {
        cout << "0" << "\n";
        for (int i = 0; i < n; ++i) {
            cout << "0 ";
        }
    }
    else {
        cout << r << "\n";
        for (auto k : a) {
            int s = 0, c = r;
            while (c >= 0) {
                s += min(c/k.t, k.z);
                c -= min(c, k.t * k.z);
                c -= k.y;
            }
            cout << min(s, m) << " ";
            m -= s;
        }
        cout << "\n";
    }
}
