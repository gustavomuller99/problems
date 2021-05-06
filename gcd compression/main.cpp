#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n; n=2*n; int o=0,e=0;
        vector<int> in(n);
        vector<int> gone(n);
        for (int i=0;i<n;++i) {
            cin>>in[i];
            (in[i]%2) ? o++ : e++;
        }
        int k = 0;
        if(!(o%2) && !(e%2)) {
            for (int i=0;i<n&&k<2;++i) {
                if (o!=0==in[i]%2) {gone[i] = 1;k++;}
            }
        } else {
            for (int i=0;i<n&&k<1;++i) {
                if(in[i]%2) {gone[i]=1;k++;}
            }
            for (int i=0;i<n&&k<2;++i) {
                if(!(in[i]%2)) {gone[i]=1;k++;}
            }
        }
        for (int i=0;i<n;++i) {
            if(!gone[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if(gone[j]) {}
                    else if(in[i]%2 && in[j]%2 || !(in[i]%2) && !(in[j]%2)) {cout<<i+1<<" "<<j+1<<endl;gone[i]=1;gone[j]=1; break;}
                }
            }
        }
    }
}
