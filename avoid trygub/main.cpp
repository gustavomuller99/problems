#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc;cin>>tc;
    while(tc--) {
        int s;cin>>s;
        string a,b; cin>>a;
        int t=0,r=0;
        for(char c : a) {
            if(c=='t') t++;
            if(c=='r') r++;
        }
        for (int i = 0; i < t; ++i) b+='t';
        for(char c : a) {
            if(c!='t' && c!='r') b+=c;
        }
        for (int i = 0; i < r; ++i) b+='r';
        cout << b << "\n";
    }
}
