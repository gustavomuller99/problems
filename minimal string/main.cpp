#include <bits/stdc++.h>
using namespace std;

int main() {
    string in; cin >> in;
    string u;
    stack<int> t;
    vector<int> a(27);
    for (int i = 0; i < in.size(); ++i) {
        a[in[i]-'a']++;
    }
    int k;
    for (int i = 0; i < 27; ++i) {
        if(a[i] > 0) {
            k = i;
            break;
        }
    }
    for (int i = 0; i < in.size(); ++i) {
        if(in[i] == k+'a') {
            u += in[i];
        } else {
            t.push(in[i]);
        }
        a[in[i]-'a']--;
        if(a[k] <= 0) {
            for (int j = k; j < 27; ++j) {
                if (a[j] > 0) {
                    k = j;
                    break;
                }
            }
        }
    }
    while(!t.empty()) {
        u += (char) t.top();
        t.pop();
    }
    cout << u << endl;
}
