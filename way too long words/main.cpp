#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    while(n--) {
        string in; cin>>in;
        (in.length()>10)?cout<<in[0]<<in.length()-2<<in[in.length()-1]<<endl:cout<<in<<endl;
    }
}
