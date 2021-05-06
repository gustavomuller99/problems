#include <bits/stdc++.h>
using namespace std;
bool is_p(int i) {
    for (int k = 2; k*k <= i; k++) {
        if(i % k == 0) return false;
    }
    return true;
}
int main() {
    int cnt = 0;
    vector<int> q;
    for (int i = 2; i < 50; ++i) {
        if(is_p(i)) cout << i << "\n";
        else continue;
        fflush(stdout);
        string in; cin>>in;
        if(in[0] == 'y') q.push_back(i*i), cnt++;
    }
    if(cnt >= 2) cout << "composite";
    else {
        bool ans = true;
        for (int i = 0; i < q.size() && q[i] < 100; ++i) {
            cout << q[i] << "\n";
            fflush(stdout);
            string in; cin>>in;
            if(in[0] == 'y') ans = false;
        }
        if(ans) cout << "prime";
        else cout << "composite";
    }
}
