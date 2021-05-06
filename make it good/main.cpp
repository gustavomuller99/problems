#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;++i) { cin>>a[i]; }
        int p = n-1;
        while (a[p] <= a[p-1] && p > 0) p--;
        while (a[p] >= a[p-1] && p > 0) p--;
        cout << p << endl;
    }
}
