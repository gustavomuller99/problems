#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string in; cin>>in;
    ll v=0,o=0,ans=0;
    for (int i = 1; i < in.size(); ++i) {
        if(in[i]=='v'&&in[i-1]=='v') {
            ans+=o;
            v++;
        } if(in[i]=='o') {
            o+=v;
        }
    }

    cout<<ans<<endl;
}
