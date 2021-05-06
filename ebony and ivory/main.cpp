#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while(c % b && c > 0) c -= a;
    cout << (c >= 0 ? "Yes" : "No") << "\n";
}
