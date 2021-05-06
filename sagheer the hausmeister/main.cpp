#include <bits/stdc++.h>
using namespace std;
int ilr[15], ill[15];
int last_floor;
int n, m;
int minTime (bool enter_left, int floor, int floor_size = m + 1) {
    if(floor == last_floor) {
        if(enter_left) return ill[floor];
        else return ilr[floor];
    }

    int time = 0;
    int time_go_right;
    int time_go_left;
    if(ill[floor] == 0 && ilr[floor] == 0){
        return 1 + minTime(enter_left, floor - 1, floor_size);
    }
    else if(enter_left) {
        time += ill[floor];
        //go right
        time_go_right = time + floor_size - ill[floor] + 1 + minTime(false, floor-1);
        //go left
        time_go_left = time + ill[floor] + 1 + minTime(true, floor-1);
    } else {
        time += ilr[floor];
        //go right
        time_go_right = time + ilr[floor] + 1 +minTime(false, floor-1);
        //go left
        time_go_left = time + floor_size - ilr[floor] + 1 + minTime(true, floor-1);
    }
    if(time_go_left > time_go_right) return  time_go_right;
    else return time_go_left;
}

int main() {
    cin >> n >> m;
    string building[n];
    last_floor = n-1;

    for(int i = 0; i < n; i++) {
        cin >> building[i];
    }
    for(int i = 0; i < n; i++) {
        int lr = 0;
        int ll = m + 1;
        for(int j = 1; j <= m; j++) {
            if(building[i][j] == '1') {
                if(j > lr) lr = j;
                if(j < ll) ll = j;
            }
        }
        ilr[i] = (m+1) - ll;
        ill[i] = lr;
        if(ilr[i] && ill[i] && i < last_floor) last_floor = i;
    }
    cout << minTime(true, n-1) << endl;

}

