#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<vector<int>> d;
vector<vector<ll>> v;
ll a,b,n;
int f(int i, int j) {
    if(d[i][j] != -1) return d[i][j];
    if(j == 0) v[i][j] = pow(i + a, b);
    else v[i][j] = v[i][j-1] * (i + a);
    if(b == 1 && j == 0 && v[i][j] > sqrt(n)) {
        bool w = !((n - v[i][j]) % 2);
        if((i + j) % 2) {
            if(w) d[i][j] = 2;
            else d[i][j] = 1;
        } else {
            if(w) d[i][j] = 1;
            else d[i][j] = 2;
        }
    } else if(a == 1 && i == 0 && v[i][j] > log2(n)) {
        d[i][j] = 0;
    } else if(v[i][j] >= n) {
        if((i + j) % 2) d[i][j] = 2;
        else d[i][j] = 1;
    } else {
        int r1 = f(i+1,j), r2 = f(i,j+1);
        if((i + j) % 2) {
            if(r1 == 2 || r2 == 2) d[i][j] = 2;
            else if(r1 == 1 && r2 == 1) d[i][j] = 1;
            else d[i][j] = 0;
        } else {
            if(r1 == 1 || r2 == 1) d[i][j] = 1;
            else if(r1 == 2 && r2 == 2) d[i][j] = 2;
            else d[i][j] = 0;
        }
    }
    return d[i][j];
}
int main() {
    cin>>a>>b>>n;
    d.resize(40000, vector<int> (30, -1));
    v.resize(40000, vector<ll> (30));
    int r = f(0, 0);
    if(r == 0) cout << "Missing";
    if(r == 1) cout << "Masha";
    if(r == 2) cout << "Stas";
}
