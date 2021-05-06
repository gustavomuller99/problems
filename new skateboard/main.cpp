#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll ans = 0;
    string s; cin>>s;
    for (int i = 0; i < s.size(); ++i) if((s[i]-48)%4==0) ans++;
    for (int j = 1; j < s.size(); ++j) if (((s[j-1]-48) * 10 + s[j]-48) % 4 == 0) ans+=j;
    cout<<ans<<endl;
}
