#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin>>n;
    vector<int> p(n+1);
    vector<int> path;
    for (int i=2;i<=n;++i) {cin>>k; p[i]=k;}
    k = n; path.push_back(k);
    while(k!=1) {
        path.push_back(p[k]);
        k = p[k];
    }
    for(auto it = path.rbegin(); it != path.rend(); it++) {cout<<*it<<" ";}
}
