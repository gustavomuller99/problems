#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        string input;
        cin >> input;

        vector<vector<char>> equals(k/2 + 1);
        for(int i = 0; i < n/k; i++) {
            for(int j = i*k; j < (i+1)*k - k/2; j++) {
                equals[j - i*k].push_back(input[j]);
                if(j != ((i+1)*k - (j-i*k) - 1)) equals[j - i*k].push_back(input[(i+1)*k - (j-i*k) - 1]);
            }
        }

        int changes = 0;
        for(const auto& i : equals) {
            vector<int> z(26);
            for(char x : i) {
                z[x-'a']++;
            }
            int highest = max_element(z.begin(), z.end()) - z.begin();
            for(char x : i) {
                if(x-'a' != highest) changes++;
            }
        }
        cout << changes << endl;
    }

}


