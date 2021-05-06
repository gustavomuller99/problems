#include <bits/stdc++.h>
using namespace std;
string in;

int solve(char c, int l, int r) {
    if(l==r) return in[l] != c;
    int mid = (l+r) / 2;
    int a=0, b=0;
    for (int i=l;i<=mid;++i) {
        if(in[i] == c) a++;
    }
    for (int i=mid+1;i<=r;++i) {
        if(in[i] == c) b++;
    }
    int low = (mid+1-l) - a + solve(c+1, mid+1, r);
    int hi = (r-mid) - b + solve(c+1, l, mid);
    //cout << c << " " << l << " " << r << " " << low << " " << hi << endl;
    return min(low, hi);
}

int main() {
    int t; cin>>t;
    while(t--) {
        int n;
        cin>>n>>in;
        cout<<solve('a', 0, in.size()-1)<<endl;
    }
}
