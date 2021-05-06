#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int x,y,xe=0,ye=0; cin>>x>>y;
        string s; cin>>s;
        vector<int> m(4);
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == 'R') xe++, m[0]++;
            if(s[i] == 'L') xe--, m[1]++;
            if(s[i] == 'U') ye++, m[2]++;
            if(s[i] == 'D') ye--, m[3]++;
        }
        bool ans = true;
        if((ye < y && m[3] < y - ye) || (ye > y && m[2] < ye - y)) ans = false;
        if((xe < x && m[1] < x - xe) || (xe > x && m[0] < xe - x)) ans = false;
        cout << (ans ? "YES\n" : "NO\n");
    }
}
