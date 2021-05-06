#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin>>s;
    int l=0,u=0,ans=s.size();
    for (int j = 0; j < s.size(); ++j) {
        if(s[j]<95) u++;
    }
    if(u+l<ans) ans=u+l;
    for (int i = 0; i < s.size(); ++i) {
        (s[i]>95) ? l++ : u--;
        if(u+l<ans) ans=u+l;
    }
    cout<<ans<<endl;
}
