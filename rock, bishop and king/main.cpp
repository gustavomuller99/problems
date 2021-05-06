#include <bits/stdc++.h>
using namespace std;

int main() {
    int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
    int x = abs(r1-r2); int y = abs(c1-c2);
    cout<<(r1==r2||c1==c2 ? 1 : 2)<<" ";
    if(r1%2&&c1%2||!(r1%2)&&!(c1%2)) {
        if(!( r2%2&&c2%2 || !(r2%2)&&!(c2%2) )) cout<<0<<" ";
        else {
            if (x == y) cout << 1 << " ";
            else cout << 2 << " ";
        }
    } else {
        if(!( r2%2&&!(c2%2) || !(r2%2)&&c2%2 )) cout<<0<<" ";
        else {
            if (x == y) cout << 1 << " ";
            else cout << 2 << " ";
        }
    }
    cout<<min(x,y)+abs(x-y)<<endl;
}
