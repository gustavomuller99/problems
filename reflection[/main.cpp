#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b,ans="";
    cin>>a>>b;
    while(a.size() < b.size()) a = '0' + a;
    bool bg = false, sm = false;
    for (int i = 0; i < a.size(); ++i) {
        if((bg || a[i] < '4') && (sm || b[i] > '4')) ans+='4';
        else if((bg || a[i] < '5') && (sm || b[i] > '5')) ans +='5';
        else if(bg && !sm) ans += b[i];
        else if(!bg && sm) ans += a[i];
        else {
            int da5 = abs(a[i] - '5'), db5 = abs(b[i] - '5');
            int da4 = abs(a[i] - '4'), db4 = abs(b[i] - '4');
            if(da5 < db5 && da5 < da4 && da5 < db4) ans += a[i];
            else if(db5 < da4 && db5 < db4) ans += b[i];
            else if(da4 < db4) ans += a[i];
            else ans += b[i];
        }
        if(!sm && ans[i] > a[i]) bg = true;
        if(!bg && ans[i] < b[i]) sm = true;
    }
    cout << ans << "\n";
}
