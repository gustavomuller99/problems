#include <bits/stdc++.h>
using namespace std;
vector<int> in;
int rec(int s = 0, int a = 0) {
    if(a == in.size() - 1) {
        return (s + in[a]) % 360 == 0 || (s - in[a]) % 360 == 0;
    }
    return rec(s+in[a], a+1) || rec(s-in[a], a+1);
}

int main() {
    int n; cin>>n;
    in.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>in[i];
    }
    cout<<(rec()==1 ? "YES" : "NO")<<endl;
}
