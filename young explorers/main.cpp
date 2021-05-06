#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> in(n);
        for (int i = 0; i < n; ++i) {
            cin >> in[i];
        }
        sort(in.begin(), in.end());
        int gp = 0, nd = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            k++;
            if(in[i] > nd) nd = in[i];
            if(k >= nd) {
                gp++;
                k = 0;
                nd = 0;
            }
        }
        cout << gp << endl;
    }
}
