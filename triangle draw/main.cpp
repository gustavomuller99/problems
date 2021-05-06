#include <bits/stdc++.h>
using namespace std;

void rec(int k, char e = '#', int s = -2, bool direction = true) {
    if(s < 0) {
        cout << "+ ";
        for (int i = 0; i < k + k%2; ++i) {
            cout << "-";
        }
        cout << " +";
        if(!direction) return;
    } else {
        cout << "|";
        int lower_limit = (k/2) - s/2;
        int upper_limit = (k/2) + s/2;
        for (int i = 0; i < lower_limit + k%2; ++i) {
            cout << " ";
        }
        cout << "<";
        for (int i = lower_limit; i < upper_limit; ++i) {
            cout << e;
        }
        cout << ">";
        for (int i = upper_limit; i < k; ++i) {
            cout << " ";
        }
        cout << "|";
    }
    cout << endl;
    if(!direction || s >= k ) return rec(k, (e == '#' ? '=' : '#'), s - 2, false);
    else return rec(k, (e == '#' ? '=' : '#'), s + 2, s < k);

}

int main() {
    int t; cin>>t;
    while(t--) {
        int k; cin>>k;
        rec(k);
    }
}
