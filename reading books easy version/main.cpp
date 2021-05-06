#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<vector<int>> s(3);

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(b && c) s[0].emplace_back(a);
        else if(b) s[1].emplace_back(a);
        else if(c) s[2].emplace_back(a);
    }

    int time = 0;

    sort(s[0].begin(), s[0].end());
    sort(s[1].begin(), s[1].end());
    sort(s[2].begin(), s[2].end());
    int msize = min(s[1].size(), s[2].size());

    for(int i = 0, j = 0; (i < s[0].size()) || (j < msize);) {
        if(j < msize) {
            if(i < s[0].size()) {
                if (s[0][i] < (s[1][j] + s[2][j])) {
                    time += s[0][i];
                    i++;
                } else {
                    time += s[1][j] + s[2][j];
                    j++;
                }
            } else {
                time += s[1][j] + s[2][j];
                j++;
            }
        } else {
            time += s[0][i];
            i++;
        }
        k--;
        if(!k) {cout << time << endl; break;}
    }
    if(k) cout << "-1" << endl;
}
