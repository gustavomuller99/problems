#include <bits/stdc++.h>
using namespace std;
int w,l;
vector<int> s;
int main() {
    cin>>w>>l;
    s.resize(w);
    for (int i = 0; i < w-1; ++i) cin>>s[i];
    int ans = INT_MAX, sum = 0;
    for (int i = 0; i < l; ++i) sum += s[i];
    ans = sum;
    for (int i = l; i < w-1; ++i) {
        sum -= s[i-l];
        sum += s[i];
        ans = min(ans, sum);
    }
    cout << ans;

}
