#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--) {
        set<int> s;
        int n, k;
        cin>>n>>k;
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            s.insert(x);
        }
        if(s.size() > k) {
            cout<<"-1"<<endl;
            continue;
        }
        cout<<n*k<<endl;
        for (int j = 0; j < n; ++j) {
            for(auto x : s) {
                cout<<x<<" ";
            }
            for(int i = 0; i < k-s.size(); i++) {
                cout<<1<<" ";
            }
        }
        cout<<endl;
    }
}
