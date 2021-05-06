#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, r; cin >> k >> r;
    int i = 1;
    for (; i <= 10; ++i) {
        int m = (k * i) % 10;
        if(m == r || m == 0) break;
    }
    cout << i << "\n";
}
