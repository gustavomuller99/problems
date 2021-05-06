#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int l,r,c;
int rec(int lx, int rx, int i = 0) {
    if(lx >= l && rx < r) return a[i];
    if(rx < l || lx >= r) return INT_MAX;
    int mid = (lx + rx) / 2;
    return min(rec(lx, mid, 2*i+1), rec(mid+1, rx, 2*i+2));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;cin>>t;
    while(t--) {
        int n, k=1;cin>>n;
        while(k < n) k*=2; k*=2; k--;
        a.resize(k);
        for (int i = k/2; i < k/2 + n; ++i) cin>>a[i];
        for (int i = k/2-1; i >= 0; --i) a[i] = min(a[2*i+1], a[2*i+2]);
        string ans;
        l = 0, r = n, c = 1;
        while(c != n) {
            int m = rec(0, k/2);
            if(m == c) ans += '1';
            else break;
            if(a[l+k/2] == c) l++;
            else if(a[r-1+k/2] == c) r--;
            else {
                if (m == c) c++;
                break;
            }
            c++;
        }
        for (int i = c; i < n; ++i) ans += '0';
        sort(a.begin()+k/2, a.begin()+k/2+n);
        bool p = true;
        for (int i = k/2; i < k/2+n; ++i) if(a[i] != i+1-k/2) p = false;
        if(p) ans += '1';
        else ans += '0';
        for(auto it = ans.rbegin(); it != ans.rend(); it++) cout << *it;
        cout << "\n";
    }
}
