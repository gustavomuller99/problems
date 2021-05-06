#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, l = -1, r = -1; cin>>n;
    vector<int> a(n);
    vector<queue<int>> pos(n+1);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        pos[a[i]].push(i);
    }
    for (int i = 1; i <= n; ++i) pos[i].push(INT_MAX);
    l = a[0]; ans = 1; pos[a[0]].pop();
    for (int i = 1; i < n; ++i) {
        if(a[i] == l || a[i] == r);
        else if(r == -1 || pos[r].front() > pos[l].front()) r = a[i], ans++;
        else l = a[i], ans++;
        pos[a[i]].pop();
    }
    cout << ans << "\n";
}
