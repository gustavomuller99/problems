#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int j;
        int oc[8000] = {0};
        vector<int> a;
        for(int i = 0; i < n; i++) {
            cin >> j;
            a.push_back(j);
            oc[j - 1] += 1;
        }
        // instead of going through each element searching for sum, go to each possible sum summing the amount of
        // correspondent terms equal to sum.
        int ans = 0;
        for(int l = 0; l < n; l++) {
            int sum = 0;
            for(int r = l; r < n; r++) {
                sum += a[r];
                if(l == r) continue;
                if(sum <= n) { // because no term is higher than n
                    ans += oc[sum - 1];
                    oc[sum - 1] = 0;
                }
            }
        }
        cout << ans << endl;
    }
}
