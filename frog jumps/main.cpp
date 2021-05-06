#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin>>t;
    while(t--) {
        string i;
        cin >> i;
        vector<int> sz(i.size() + 1);
        int k=0;
        if(i[0]=='L') {k=1;sz[0]=1;}
        for (int j = 1; j < i.size(); ++j) {
            if (i[j] == 'L') {
                sz[j] += sz[j - 1]+1;
                if (sz[j] > k) k = sz[j];
            }
        }
        cout<<(k==0 ? 1 : k+1)<<endl;
    }
}
