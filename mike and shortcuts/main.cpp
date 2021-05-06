#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n; vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i], s[i]--;
    vector<int> d(n, INT_MAX); d[0] = 0;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int r = q.front();
        q.pop();
        if(r > 0 && d[r - 1] > d[r] + 1) d[r - 1] = d[r] + 1, q.push(r - 1);
        if(r < n - 1 && d[r + 1] > d[r] + 1) d[r + 1] = d[r] + 1, q.push(r + 1);
        if(d[s[r]] > d[r] + 1) d[s[r]] = d[r] + 1, q.push(s[r]);
    }
    for(int k : d) {
        cout << k << " ";
    }
}
