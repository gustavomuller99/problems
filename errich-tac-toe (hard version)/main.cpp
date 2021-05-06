#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<string> g(n);
        vector<int> rx(3), ro(3);
        int rxx, rxi = 0, roo, roi = 0;
        for (int i = 0; i < n; ++i) cin>>g[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(g[i][j] == 'X') {
                    rx[(i+j)%3]++;
                }
                else if(g[i][j] == 'O') {
                    ro[(i+j)%3]++;
                }
            }
        }
        int sum = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(i == j) continue;
                if(rx[i] + ro[j] < sum) sum = rx[i] + ro[j], rxi = i, roi = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(g[i][j] == 'X' && (i+j)%3 == rxi) g[i][j] = 'O';
                if(g[i][j] == 'O' && (i+j)%3 == roi) g[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << g[i] << "\n";
        }
    }
}