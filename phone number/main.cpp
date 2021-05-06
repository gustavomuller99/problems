#include <bits/stdc++.h>
using namespace std;

int main() {
    string in; cin>>in;
    vector<int> a(in.size());
    for (int i = 0; i < a.size(); ++i) a[i] = in[i] - '0';
    unsigned long long d[a.size()][10]; memset(d, 0, sizeof(d));
    for (int i = 0; i < 10; ++i) d[0][i] = 1;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < 10; ++j) {
            d[i][(a[i]+j)/2] += d[i-1][j];
            if((a[i]+j)%2) d[i][(a[i]+j)/2+1] += d[i-1][j];
        }
    }
    unsigned long long ans = 0; bool s = true;
    for (int i = 1; i < a.size(); ++i) if(abs(a[i] - a[i-1]) > 1) s = false;
    if(s) ans--;
    for (int i = 0; i < 10; ++i) ans += d[a.size()-1][i];
    cout << ans;
}
