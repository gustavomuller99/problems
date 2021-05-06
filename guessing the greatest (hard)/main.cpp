#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int l = 1, r = n, p1, p2;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin>>p1;
    if(p1 != l && p1 != r) {
        cout << "? " << p1 << " " << r << "\n";
        cout.flush();
        cin >> p2;
        if (p1 == p2) l = p1;
        else r = p1;
    }
    while(l + 1 < r) {
        int mid = (l+r) / 2;
        if(mid >= p1) cout << "? " << p1 << " " << mid << "\n";
        else cout << "? " << mid << " " << p1 << "\n";
        cout.flush();
        cin >> p2;
        if(p2 == p1) {
            if(mid > p1) r = mid;
            else l = mid;
        } else {
            if(mid > p1) l = mid;
            else r = mid;
        }
    }
    int ans;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin>>ans;
    if(ans == l) cout << "! " << r;
    else cout << "! " << l;
    multiset<int> ms;
}
