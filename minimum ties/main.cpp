#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        int am = (n-1)/2;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = i+1; j < n; ++j) {
                if(cnt < am) cout << 1;
                else if(cnt == am && n%2 == 0) cout << 0;
                else cout << -1;
                cnt++;
                cout << " ";
            }
        }
        cout << "\n";
    }
}
