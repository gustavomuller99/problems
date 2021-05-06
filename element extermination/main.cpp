#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> in(n);
        for (int i=0;i<n;++i) { cin >> in[i]; }
        cout << (in[0] < in[n-1] ? "YES" : "NO") << endl;
    }
}
