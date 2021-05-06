#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--) {
        vector<long long> i(3);
        for (int j=0;j<3;++j) { cin>>i[j]; } sort(i.begin(), i.end(), greater<>());
        if(i[0]!=i[1]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<i[0]<<" "<<i[2]<<" "<<i[2]<<endl;
    }
}
