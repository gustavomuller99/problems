#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int l = 1, r = n;
    while(l + 1 < r) {
        int p1, p2, mid = (l+r) / 2;
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        cin>>p1;
        if(p1 >= mid) {
            cout << "? " << mid << " " << r << "\n";
            cout.flush();
            cin>>p2;
            if(p1 == p2) l = mid;
            else r = mid;
        }
        else {
            cout << "? " << l << " " << mid << "\n";
            cout.flush();
            cin>>p2;
            if(p1 == p2) r = mid;
            else l = mid;
        }
    }
    int ans;
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    cin>>ans;
    if(ans == l) cout << "! " << r;
    else cout << "! " << l;
}
