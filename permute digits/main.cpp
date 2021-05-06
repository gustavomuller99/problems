#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b; cin >> a >> b;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i+1; j < a.size(); ++j) {
            string cp = a;
            swap(cp[i], cp[j]);
            if(stoll(cp) >= stoll(a) && stoll(cp) <= stoll(b)) a = cp;
            else break;
        }
    }
    cout << a;
}
