#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n, k; cin>>n>>k;
        for (int i = 1; i <= k-(n-k)-1; ++i) {
            cout << i << " ";
        }
        for (int i = k; i >= k-(n-k); --i) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
