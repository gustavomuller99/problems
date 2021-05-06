#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ifstream	fin("input.txt");
    std::ofstream	fout("output.txt");
    int n; fin>>n;
    vector<pair<int,int>> a(n);
    vector<int> in(n);
    int ng=0,z=0;
    for (int i = 0; i < n; ++i) {
        fin>>in[i];
        if(in[i]<0) ng++;
        else if(in[i]==0) z++;
    }
    int ans=INT_MAX;
    for (int i = 0; i < n-1; ++i) {
        if(in[i]<0) {
            a[i].first=1;
            if(i) {
                a[i].first+=a[i-1].first;
                a[i].second = a[i-1].second;
            }
        }
        else if(in[i]>0) {
            a[i].second=1;
            if(i) {
                a[i].second += a[i-1].second;
                a[i].first = a[i-1].first;
            }
        } else {
            if(i) {
                a[i].second = a[i-1].second;
                a[i].first = a[i-1].first;
            }
        }
        if(a[i].second + ng - a[i].first + z < ans) ans = a[i].second + ng - a[i].first + z;
    }
    fout<<ans<<endl;
}
