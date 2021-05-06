#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fl;
pair<ll,ll> d_floors(ll start, ll end, ll e_end) {
    ll d_start_end, d_start_e_end;
    if(end >= start) {
        d_start_end = end-start;
    } else {
        d_start_end = fl - start + end;
    }

    if(e_end >= start) {
        d_start_e_end = e_end-start;
    } else {
        d_start_e_end = fl - start + e_end;
    }

    if(d_start_end < d_start_e_end) return make_pair(d_start_end, end);
    else return make_pair(d_start_e_end, e_end);

}
int main() {
    ll n,m;cin>>n>>m;
    fl = m+m-2;
    for (int i=0;i<n;++i) {
        ll s_floor,f_floor,time; cin>>s_floor>>f_floor>>time;
        s_floor--; f_floor--;
        if(s_floor==f_floor) {cout<<time<<endl; continue;}
        ll s_equivalent_floor = 2*(m-1) - s_floor;
        ll f_equivalent_floor = 2*(m-1) - f_floor;
        ll initial_elevator_floor = (time)%fl;
        pair<ll,ll> k = d_floors(initial_elevator_floor, s_floor, s_equivalent_floor);
        time += k.first;
        pair<ll,ll> l = d_floors(k.second, f_floor, f_equivalent_floor);
        time += l.first;
        cout<<time<<endl;
    }
}
