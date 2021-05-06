#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {

    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int t; cin>>t;
        a.push_back(t);
    }
    vector<int> b;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int k = lcm(a[i], a[j]);
            b.insert(b.begin(), k);
        }
    }
    for(int i = 0; i < b.size() - 1; i++) {
        int k = gcd(b[i], b[i+1]);
        b[i+1] = k;
    }

    cout << b[b.size()-1] << endl;

}
