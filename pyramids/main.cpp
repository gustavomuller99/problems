#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
int main() {
    double l1,l2,l3; cin>>l1>>l2>>l3;
    double v1 = l1*l1*l1*sqrt(2)/12;
    double v2 = l2*l2*l2/(3*sqrt(2));
    double v3 = 5*pow(l3, 3)*(sqrt(1 - (1/(4*sin((36*PI)/180)*sin((36*PI)/180)))))/(12*tan((36*PI)/180));
    cout << setprecision(20) << v1+v2+v3 << "\n";
}
