#include <bits/stdc++.h>
using namespace std;

int main() {
    string in; cin>>in;
    string h = "heidi";
    int k = 0;
    for (int i = 0; i < in.size(); ++i) {
        if(in[i]==h[k]) k++;
        if(k==h.size()) break;
    }
    (k==h.size()) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}
