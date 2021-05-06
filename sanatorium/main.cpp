#include <bits/stdc++.h>
using namespace std;
#define INT unsigned long long
int main() {
    vector<INT> a(3);
    int mx = 0;
    for (int i = 0; i < 3; ++i) { cin >> a[i]; if(a[i] > a[mx]) mx = i; }
    a[mx]--;
    cout << (a[mx] >= a[(mx+1)%3] ? a[mx] - a[(mx+1)%3] : 0) + (a[mx] >= a[(mx+2)%3] ? a[mx] - a[(mx+2)%3] : 0) << "\n";
}
