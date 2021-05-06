#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        int cnt1 = 0, cnt2 = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            if(x == 1) cnt1++;
            else cnt2++;
        }
        sum = cnt2*2 + cnt1;
        if(sum%2==0) {
            sum /= 2;
            while(sum != 0) {
                if(sum > 1 && cnt2) sum -= 2, cnt2--;
                else if(cnt1) sum--, cnt1--;
                else break;
            }
            if(sum==0) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
}
