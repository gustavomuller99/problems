#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<string> in(n);
    vector<int> s;
    for (int i = 0; i < n; ++i) {
        cin>>in[i];
    }
    int sz = in[0].size();
    for (int i = 0; i < n; ++i) {
        int sh = 0;
        for (int j = 0; j < n; ++j) {
            string c = in[j];
            for (int k = 0; k < sz; ++k) {
                if(in[i]==c) {break;}
                sh++;
                c.push_back(c[0]);
                c.erase(0,1);
                if(k==sz-1) {cout<<"-1"<<endl; return 0;}
            }
        }
        s.push_back(sh);
    }
    int ans = INT_MAX;
    for(int k : s) {
        ans = min(ans, k);
    }
    cout << ans << endl;
}
