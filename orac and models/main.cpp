#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& models) {



}

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;
        vector<int> models(n+1);
        vector<int> f(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> models[i];
            f[i] = 1;
        }

        // for every element of models array, find the maximum of beautiful arrangements ended in i
        // at each iteration i, f[i] have the maximum amount of beautiful arrangements from i to 0
        for(int i = 1; i <= n; i++) {
            for(int j = i*2; j <=n; j+=i) {
                if(models[i] < models[j]) f[j] = max(f[j], f[i] + 1);
            }
        }

        int ans = 0;
        for(int i : f) {
            ans = max(ans, i);
        }

        cout << ans << endl;

    }

}
