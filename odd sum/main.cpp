#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int s = 0, m = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        if(k > 0) {
            s += k;
        }
        if(k % 2 && abs(k) < abs(m)) m = k;
    }
    cout << (s % 2 ? s : s - abs(m)) << endl;
}
