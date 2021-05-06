#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(int b, int e, string &s) {
    bool is = true;
    while(b < e) {
        if(s[b] != s[e]) {is = false; break;}
        b++;
        e--;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    int k;
    cin >> s >> k;
    vector<int> valid_sizes;

    for(int j = 0; j < s.size(); j++) if(is_palindrome(0,j,s)) valid_sizes.push_back(j+1);

    bool ans;
    for(int size : valid_sizes) {
        int n_palindromes = k-1;
        ans = true;
        for (int i = size; i != s.size(); i += size) {
            if(i + size <= s.size()) {
                if (!is_palindrome(i, i + size - 1, s)) {
                    ans = false;
                    break;
                }
            } else {
                ans = false;
                break;
            }
            n_palindromes--;
        }
        if (ans && !n_palindromes) {ans = true; break;}
        else {ans = false;}
    }
    if(ans) cout << "YES";
    else cout << "NO";

}
