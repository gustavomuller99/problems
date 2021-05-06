#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int a, b, p; cin >> a >> b >> p;
        string rd; cin >> rd;
        vector<unsigned long long> c(rd.size());
        c[rd.size()-1] = 0;
        c[rd.size()-2] = rd[rd.size()-2] == 'B' ? b : a;
        for (int i = rd.size() - 3; i >= 0; --i) {
            if(rd[i] == rd[i+1]) c[i] = c[i+1];
            else c[i] = c[i+1] + (rd[i] == 'B' ? b : a);
        }
        int l = -1, r = rd.size();
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if(c[mid] > p) l = mid;
            else r = mid;
        }
        cout << r+1 << "\n";
    }
}
