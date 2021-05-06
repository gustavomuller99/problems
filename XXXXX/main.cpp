#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, x;
int main() {
    cin>>t;
    while(t--) {
        cin >> n >> x;
        ll k, sum=0;
        int low=-1, hi;
        for (int i = 0; i < n; ++i) {
            cin >> k; sum+=k;
            if(k%x) {
                if (low == -1) low = i+1;
                hi = i;
            }
        }
        if(sum%x) cout<<n<<endl;
        else if(low==-1) cout<<"-1"<<endl;
        else cout<<n-min(low, n-hi)<<endl;
    }
}
