#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i].second>>a[i].first;
    sort(a.begin(), a.end());
    int k = 1, h = a[0].first;
    for (int i = 1; i < n; ++i) {
        if(a[i].second > h) k++, h = a[i].first;
    }
    cout << k;
}
