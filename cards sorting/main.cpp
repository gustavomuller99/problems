#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,k; cin>>n; k=n;
    ll ans = 0;
    vector<deque<int>> a(1e5+1);
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x; a[x].push_back(i);
    }
    int pos=0,r=0;
    for (int i = 1; i < 1e5+1; ++i) {
        if(!a[i].empty()) {
            int x = a[i].back();
            while(!a[i].empty()) {
                int y = a[i].back();
                if(y > pos) a[i].pop_back(), r++;
                else break;
            }
            if(x > pos) pos = x;
            if(!a[i].empty()) {
                ans += k;
                k -= r;
                i--;
                r = 0; pos = 0;
            }
        }
    }
    ans += k;
    cout << ans;
}
