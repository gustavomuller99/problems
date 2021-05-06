#include <bits/stdc++.h>
using namespace std;
int h, p = -1, s1 = 0, s2 = 0;
vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> h; v.resize(h + 1);
    for (int i = 0; i <= h; ++i) cin >> v[i];
    for (int i = 0; i < h; ++i) {
        if(v[i] > 1 && v[i+1] > 1) { p = i; break; }
    }
    if(p == -1) cout << "perfect" << "\n";
    else {
        cout << "ambiguous" << "\n";
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i]; ++j) {
                cout << s1 << " ";
            }
            s1 += v[i];
        }
        cout << "\n";
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < v[i]; ++j) {
                cout << s2 << " ";
            }
            s2 += v[i];
        }
        for (int i = 0; i < v[p]; ++i) cout << s2 << " ";
        for (int i = 0; i < v[p+1] / 2; ++i) cout << s2 + 1 << " ";
        for (int i = v[p+1] / 2; i < v[p+1]; ++i) cout << s2 + 2 << " ";
        s2 += v[p+1] + v[p];
        for (int i = p+2; i < v.size(); ++i) {
            for (int j = 0; j < v[i]; ++j) {
                cout << s2 << " ";
            }
            s2 += v[i];
        }
    }
}
