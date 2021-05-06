#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int l = 1, r = n;
    while(l + 2 < r) {
        int mid = (l + r) / 2,a,b;
        cout << "? " << mid << "\n";
        fflush(stdout);
        cin>>a;
        cout << "? " << mid + 1 << "\n";
        fflush(stdout);
        cin>>b;
        if(a > b) l = mid;
        else r = mid + 1;
    }
    int a, b, c;
    cout << "? " << l << "\n"; fflush(stdout);
    cin >> a;
    cout << "? " << r << "\n"; fflush(stdout);
    cin >> c;
    if(r - l == 2) {
        cout << "? " << l+1 << "\n"; fflush(stdout);
        cin >> b;
    }
    if(r - l < 2) b = c;
    if(r - l == 2 && b < a && b < c) cout << "! " << l+1 << "\n";
    else if(a < b) cout << "! " << l << "\n";
    else cout << "! " << r << "\n";
}
