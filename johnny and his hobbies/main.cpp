#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h = INT_MIN;
        cin >> n;
        vector<int> num(n);
        for(int i = 0; i < n; i++) {
            cin >> num[i];
            if(num[i] > h) h = num[i];
        }
        sort(num.begin(), num.end());
        int sol = -1, p = 1;
        bool ans;
        while(h >> p) p++;
        for(int k = 1; k <= 1 << p; k++) {
            vector<int> n_num(n);
            ans = true;
            for(int i = 0; i < n; i++) {
                n_num[i] = num[i] ^ k;
            }
            sort(n_num.begin(), n_num.end());
            for(int i = 0; i < n; i++) {
                if(num[i] != n_num[i]) ans = false;
            }
            if(ans) {sol = k; break;}
        }
        cout << sol << endl;
    }
}
